在 C++ 中，`std::make_shared` 和直接使用 `std::shared_ptr` 构造函数（`shared_ptr<T>(new T)`) 都可以创建智能指针，但 **`std::make_shared` 通常是更好的选择**。以下是详细对比：

---

### **1. 两种方式的对比**
#### **(1) `std::make_shared`（推荐）**
```cpp
auto p = std::make_shared<std::vector<int>>();
```
✅ **优点**：
1. **更高效**  
   - `make_shared` 会一次性分配内存，既存储 `std::vector<int>` 对象，又存储 `shared_ptr` 的控制块（引用计数等）。  
   - 而 `shared_ptr<T>(new T)` 需要两次分配（先 `new`，再分配控制块），可能更慢且内存碎片化。

2. **异常安全**  
   - 如果 `new` 成功但 `shared_ptr` 构造失败（如内存不足），`make_shared` 能避免内存泄漏。  
   - 例如：
     ```cpp
     foo(std::shared_ptr<int>(new int(42)), bar()); // 如果 bar() 抛出异常，可能泄漏
     foo(std::make_shared<int>(42), bar());         // 异常安全
     ```

3. **代码更简洁**  
   - 不需要显式写 `new`，减少出错可能。

❌ **缺点**：
- 如果类重载了 `operator new`/`operator delete`，`make_shared` 无法使用自定义的内存管理方式。

#### **(2) 直接 `shared_ptr` 构造**
```cpp
std::shared_ptr<std::vector<int>> q(new std::vector<int>());
```
✅ **适用场景**：
1. 需要自定义删除器（`deleter`）时：
   ```cpp
   std::shared_ptr<FILE> fp(fopen("file.txt", "r"), fclose);
   ```
2. 需要单独控制 `shared_ptr` 和 `weak_ptr` 的生命周期时（`make_shared` 会合并内存，`weak_ptr` 可能延长对象存活时间）。

❌ **缺点**：
- 性能稍差（两次内存分配）。
- 不够异常安全（如前面所述）。

---

### **2. 性能对比（`make_shared` vs `shared_ptr(new T)`）**
| **方式**               | 内存分配次数 | 异常安全 | 适用场景          |
|-----------------------|------------|---------|-----------------|
| `make_shared<T>()`    | **1 次**   | ✅       | 默认情况（推荐）  |
| `shared_ptr<T>(new T)` | **2 次**   | ❌       | 需要自定义删除器等 |

---

### **3. 结论**
- **99% 的情况下，优先用 `std::make_shared`**，因为它更高效、更安全、更简洁。  
- **仅在需要自定义删除器或特殊内存管理时，才用 `shared_ptr<T>(new T)`**。

---

### **4. 额外建议**
如果不需要共享所有权（即不需要 `shared_ptr`），改用 `std::unique_ptr` 会更高效：
```cpp
auto p = std::make_unique<std::vector<int>>();  // C++14 引入
// 或
std::unique_ptr<std::vector<int>> p(new std::vector<int>());
``` 

---

### **最终答案**
**`std::make_shared` 是更好的选择**，除非你有特殊需求（如自定义删除器）。你的代码可以优化为：
```cpp
auto p = std::make_shared<std::vector<int>>();  // ✅ 推荐
// 而不是
std::shared_ptr<std::vector<int>> q(new std::vector<int>());  // ❌ 除非必要
```