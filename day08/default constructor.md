在C++中，编译器生成的**合成默认构造函数**（synthesized default constructor）无法为以下类别的数据成员提供初始值：

### 1. **内置类型（Built-in types）**
   - 如 `int`, `float`, `double`, `char`, `bool`, 指针等。
   - **原因**：合成默认构造函数不会初始化这些类型，其值将是**未定义的**（通常是内存中的随机值）。
   - 示例：
     ```cpp
     class Example {
         int x;       // 未初始化（值随机）
         double d;    // 未初始化
         char* ptr;   // 未初始化
     };
     ```

### 2. **常量成员（`const` members）**
   - **原因**：常量成员必须在构造函数的**初始化列表**中显式初始化，且只能初始化一次。合成默认构造函数无法做到这一点。
   - 示例：
     ```cpp
     class ConstMember {
         const int k; // 必须显式初始化（否则编译错误）
     };
     ```

### 3. **引用成员（Reference members）**
   - **原因**：引用必须在创建时绑定到对象（即初始化），且不能重新绑定。合成默认构造函数无法提供初始绑定。
   - 示例：
     ```cpp
     class RefMember {
         int& ref; // 必须显式初始化（否则编译错误）
     };
     ```

### 4. **类类型成员（Class-type members 且该类无默认构造函数）**
   - **原因**：如果某个成员是类类型（如 `AnotherClass obj`），且 `AnotherClass` **没有默认构造函数**（即它显式定义了带参数的构造函数，且未提供无参构造函数），则合成默认构造函数无法初始化该成员。
   - 示例：
     ```cpp
     class AnotherClass {
     public:
         AnotherClass(int v) {} // 自定义构造函数（无默认构造函数）
     };

     class MyClass {
         AnotherClass obj; // 合成默认构造函数无法初始化obj（编译错误）
     };
     ```

### 5. **没有默认构造函数的基类（Base classes without default constructors）**
   - **原因**：如果类继承自一个没有默认构造函数的基类，合成默认构造函数无法调用基类构造函数。
   - 示例：
     ```cpp
     class Base {
     public:
         Base(int x) {} // 无默认构造函数
     };

     class Derived : public Base {
         // 合成默认构造函数无法初始化基类（编译错误）
     };
     ```

---

### ✅ 编译器**会**初始化的成员
合成默认构造函数**会**为以下成员初始化：
- **类类型成员（Class-type members）**：如果该成员有默认构造函数（编译器生成或用户显式定义）。
- **数组成员**：会调用每个元素的默认构造函数（若元素是类类型且有默认构造函数）。

---

### 解决方案：显式定义默认构造函数
若需初始化上述成员，必须**显式定义默认构造函数**，并在初始化列表中赋值：
```cpp
class FixedExample {
    int x;
    const int k;
    int& ref;
    AnotherClass obj;

public:
    // 显式初始化所有成员
    FixedExample() : x(0), k(42), ref(x), obj(100) {} 
};
```

> **关键点**：合成默认构造函数仅处理“有默认行为的成员”（如类类型成员），对内置类型、常量、引用等需程序员显式管理。