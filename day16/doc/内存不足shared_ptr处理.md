在 C++ 中，当使用 `std::shared_ptr` 分配内存时，如果内存不足，其行为取决于 **构造方式**（`std::make_shared` vs `new` + `shared_ptr` 构造），具体处理方式如下：

---

## **1. 使用 `std::make_shared` 时**
### **（1）内存不足的行为**
```cpp
auto p = std::make_shared<std::vector<int>>();  // 可能抛出 std::bad_alloc
```
- **`std::make_shared` 会尝试一次性分配内存**（存储对象 + 控制块）。
- **如果内存不足，直接抛出 `std::bad_alloc` 异常**（不会返回 `nullptr`）。
- **不会发生内存泄漏**（因为还没分配成功）。

### **（2）如何处理？**
可以捕获异常：
```cpp
try {
    auto p = std::make_shared<std::vector<int>>();
    // 正常使用 p
} catch (const std::bad_alloc& e) {
    std::cerr << "内存分配失败: " << e.what() << std::endl;
    // 处理错误（如降级方案、退出程序等）
}
```

---

## **2. 使用 `new` + `shared_ptr` 构造时**
### **（1）内存不足的行为**
```cpp
std::shared_ptr<std::vector<int>> p(new std::vector<int>());  // 可能抛出 std::bad_alloc
```
- **`new` 失败时抛出 `std::bad_alloc`**（除非用 `std::nothrow`）。
- **如果 `new` 成功但 `shared_ptr` 控制块分配失败**：
  - C++ 标准保证 `shared_ptr` 会正确释放 `new` 分配的内存，**不会泄漏**。
  - 但仍然会抛出 `std::bad_alloc`。

### **（2）如何处理？**
同样捕获异常：
```cpp
try {
    std::shared_ptr<std::vector<int>> p(new std::vector<int>());
    // 正常使用 p
} catch (const std::bad_alloc& e) {
    std::cerr << "内存分配失败: " << e.what() << std::endl;
}
```

---

## **3. 使用 `std::nothrow` + 手动检查（不推荐）**
如果希望 `new` 失败时返回 `nullptr` 而不是抛出异常：
```cpp
auto* raw_ptr = new (std::nothrow) std::vector<int>();
if (!raw_ptr) {
    std::cerr << "new 分配失败，返回 nullptr" << std::endl;
} else {
    std::shared_ptr<std::vector<int>> p(raw_ptr);  // 交给 shared_ptr 管理
}
```
⚠️ **缺点**：
- 代码更复杂，容易出错（如果 `new` 成功但 `shared_ptr` 构造失败，仍然可能泄漏）。
- **不推荐**，除非有特殊需求（如嵌入式开发禁用异常）。

---

## **4. 总结：`shared_ptr` 内存不足的处理方式**
| **情况**               | **行为**                                                                 | **推荐处理方式**                     |
|-----------------------|-------------------------------------------------------------------------|-----------------------------------|
| **`make_shared`**     | 内存不足时直接抛出 `std::bad_alloc`，无内存泄漏                              | `try-catch` 捕获 `std::bad_alloc` |
| **`shared_ptr(new T)`** | `new` 失败抛 `std::bad_alloc`；`shared_ptr` 构造失败也会抛，但保证不泄漏       | `try-catch` 捕获 `std::bad_alloc` |
| **`nothrow new`**     | `new` 失败返回 `nullptr`，但 `shared_ptr` 构造仍可能失败，不推荐               | 尽量避免使用                        |

### **最佳实践**
✅ **优先用 `std::make_shared` + 异常捕获**：
```cpp
try {
    auto p = std::make_shared<std::vector<int>>();
    // 正常使用
} catch (const std::bad_alloc& e) {
    // 处理内存不足
}
```
✅ **如果必须用 `new`，确保异常安全**：
```cpp
try {
    std::shared_ptr<std::vector<int>> p(new std::vector<int>());
} catch (const std::bad_alloc& e) {
    // 处理错误
}
```
❌ **避免 `nothrow new` + 手动管理**（除非有特殊约束）。