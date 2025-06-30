这个问题非常好！你的观察很敏锐：**为什么 `swap(HasPtr&, HasPtr&)` 的实现不会导致递归调用自身？** 关键在于 C++ 的 **名称查找规则** 和 **ADL（Argument-Dependent Lookup）机制**。以下是详细解释：

---

### **1. 关键点：`using std::swap` 的作用**
```cpp
using std::swap;  // 引入 std::swap 到当前作用域
swap(lhs.ps, rhs.ps);  // 调用哪个 swap？
```
- 这行代码的意思是：
  - **先尝试通过 ADL 查找适合的 `swap`**（根据参数类型 `std::string*`）。
  - **如果没有找到，再回退到 `std::swap`**。

---

### **2. 为什么不会递归？**
#### **(1) `swap(lhs.ps, rhs.ps)` 的参数类型是 `std::string*`**
- `ps` 是 `std::string*`（原始指针），而 `std::string*` 没有专属的 `swap` 重载。
- **ADL 不会在 `HasPtr` 的命名空间中找到匹配的 `swap`**，因为：
  - ADL 只查找与参数类型关联的命名空间（如 `std::string` 的命名空间是 `std`，但 `std::string*` 是原生指针，无关联命名空间）。
- 因此，编译器回退到 `std::swap`，调用 **标准库的指针交换**：
  ```cpp
  // 类似于调用：
  std::swap(lhs.ps, rhs.ps);  // 交换两个指针的值
  ```

#### **(2) 如果 `ps` 是类类型（如 `std::string` 而非指针）**
假设 `ps` 是 `std::string`（而非指针）：
```cpp
class HasPtr {
private:
    std::string ps;  // 不是指针！
    int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);  // 这里会调用 std::string 的 swap！
    swap(lhs.i, rhs.i);
}
```
- 此时 `swap(lhs.ps, rhs.ps)` 的参数类型是 `std::string`。
- **ADL 会优先查找 `std::string` 的 `swap`**（在 `std` 命名空间中定义的 `std::string::swap`），而不会递归调用 `HasPtr` 的 `swap`。

---

### **3. 递归的条件**
如果错误地直接调用 `swap(lhs, rhs)`，才会导致递归：
```cpp
// 错误实现：会导致递归！
inline void swap(HasPtr& lhs, HasPtr& rhs) {
    swap(lhs, rhs);  // 无限递归调用自身！
}
```
但你的实现通过 `using std::swap` + **参数类型区分**，避免了这一问题。

---

### **4. 总结**
- **不会递归的原因**：
  1. `swap(lhs.ps, rhs.ps)` 的参数是 `std::string*`，ADL 找不到专属 `swap`，回退到 `std::swap`。
  2. `std::swap` 对指针的实现是简单的值交换（无递归）。
- **关键机制**：
  - `using std::swap` + ADL 确保优先调用最匹配的 `swap`。
  - 参数类型决定查找路径，避免误调。

---

### **5. 如果是自定义类成员**
如果 `HasPtr` 的成员是另一个自定义类（而非指针），ADL 会优先查找该类的 `swap`：
```cpp
class Foo { /* ... */ };

class HasPtr {
private:
    Foo ps;  // 自定义类
    int i;
};

// Foo 的专属 swap
void swap(Foo& a, Foo& b) { /* ... */ }

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);  // 调用 Foo 的 swap，而非 std::swap
    swap(lhs.i, rhs.i);
}
```
此时：
1. `swap(lhs.ps, rhs.ps)` 会通过 ADL 找到 `Foo` 的 `swap`。
2. 仍然不会递归调用 `HasPtr` 的 `swap`。

---

### **最终结论**
你的 `swap` 实现是安全的，因为：
1. **指针类型**：`std::string*` 的交换直接调用 `std::swap`，无递归。
2. **类类型**：ADL 会优先查找该类的 `swap`，也不会递归。
3. **通用规则**：`using std::swap` + ADL 是 C++ 中实现可扩展 `swap` 的标准做法。