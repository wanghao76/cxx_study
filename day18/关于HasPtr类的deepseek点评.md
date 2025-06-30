你的 `HasPtr` 类实现 **没有内存泄漏的风险**，并且正确使用了 **copy-and-swap** 惯用法，确保了异常安全和自赋值安全。以下是详细分析：

---

### **1. 内存管理正确性**
#### **构造函数**
```cpp
HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
```
- 动态分配 `std::string`，并由 `ps` 管理，**无内存泄漏**。

#### **拷贝构造函数**
```cpp
HasPtr(const HasPtr& hpr) : ps(new std::string(*hpr.ps)), i(hpr.i) {}
```
- 深拷贝 `std::string`，**无内存泄漏**。

#### **析构函数**
```cpp
~HasPtr() { delete ps; }
```
- 正确释放 `ps` 指向的内存，**无内存泄漏**。

#### **拷贝赋值运算符（copy-and-swap）**
```cpp
HasPtr& operator=(HasPtr hpr) {
    swap(*this, hpr);
    return *this;
}
```
- **值传递 `hpr`**：调用拷贝构造函数创建副本，异常安全。
- **交换资源**：`swap` 交换 `*this` 和 `hpr` 的资源。
- **临时对象 `hpr` 析构**：离开作用域时，`hpr` 析构函数自动释放旧资源。

**关键点**：
- 如果 `new std::string(*hpr.ps)` 抛出异常，发生在赋值操作之前，不影响 `*this` 的原有状态。
- 自赋值安全：因为参数是值传递，副本与原对象无关。

---

### **2. 自定义 `swap` 的正确性**
```cpp
inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;  // 启用 ADL（Argument-Dependent Lookup）
    swap(lhs.ps, rhs.ps);  // 交换指针（无内存分配）
    swap(lhs.i, rhs.i);    // 交换整型
}
```
- **`using std::swap` + ADL**：优先查找类型特定的 `swap`，退回到 `std::swap`。
- **交换指针**：仅交换 `std::string*`，不涉及深层拷贝，高效且安全。

---

### **3. 无内存泄漏的证明**
#### **案例 1：正常赋值**
```cpp
HasPtr a("hello");
HasPtr b("world");
a = b;  // 正确释放 a 的旧内存，b 的资源被拷贝
```
1. `b` 的值拷贝到临时对象 `hpr`。
2. `swap(a, hpr)` 交换资源。
3. `hpr` 析构时释放 `a` 的旧内存。

#### **案例 2：自赋值**
```cpp
HasPtr a("hello");
a = a;  // 安全
```
1. 创建 `a` 的副本 `hpr`（拷贝构造函数深拷贝）。
2. `swap(a, hpr)` 交换资源。
3. `hpr` 析构时释放副本的内存，不影响 `a`。

#### **案例 3：异常安全**
```cpp
HasPtr a("hello");
try {
    a = HasPtr("world");  // 如果 new 抛出异常，a 保持不变
} catch (...) {}
```
- 如果 `new` 在拷贝构造临时对象时抛出异常，`a` 的原始资源未被修改。

---

### **4. 可改进的细节（非必需）**
#### **(1) 支持移动语义（C++11）**
```cpp
HasPtr(HasPtr&& other) noexcept : ps(other.ps), i(other.i) {
    other.ps = nullptr;  // 避免被析构
}

HasPtr& operator=(HasPtr&& other) noexcept {
    swap(*this, other);
    return *this;
}
```
- 优化临时对象传递时的性能（避免深拷贝）。

#### **(2) `noexcept` 标记**
```cpp
~HasPtr() noexcept { delete ps; }
```
- 析构函数通常不应抛异常，标记为 `noexcept` 更规范。

#### **(3) 智能指针替代原始指针**
```cpp
private:
    std::unique_ptr<std::string> ps;  // 自动管理内存
```
- 彻底避免手动 `delete`，但需调整 `swap` 实现。

---

### **5. 总结**
- **你的实现完全正确**，无内存泄漏，且具备：
  - 异常安全（copy-and-swap）。
  - 自赋值安全。
  - 高效的资源管理（`swap` 仅交换指针）。
- **可选的优化**：移动语义、`noexcept`、智能指针（根据需求选择）。

现代 C++ 中，类似功能可以直接用 `std::string`（而非 `std::string*`）或 `std::unique_ptr` 减少手动管理，但当前实现已是教科书级别的正确示范。