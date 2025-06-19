# `vector.resize()` 和 `vector.reserve()` 的区别

这两个都是 C++ 中 vector 容器的成员函数，但它们的功能完全不同：

## `vector.resize(n)`

1. **改变容器大小**：调整 vector 的元素数量
2. **可能增加或减少元素**：
   - 如果 n > 当前大小，会添加新元素（默认构造或使用指定值）
   - 如果 n < 当前大小，会删除多余元素
3. **影响 size()**：调用后 size() == n
4. **可能重新分配内存**：如果 n > capacity()

```cpp
std::vector<int> v = {1, 2, 3};
v.resize(5);  // 现在 v = {1, 2, 3, 0, 0}，size=5
v.resize(2);  // 现在 v = {1, 2}，size=2
```

## `vector.reserve(n)`

1. **预留内存空间**：只是预分配内存，不改变元素数量
2. **不影响元素**：不会添加或删除任何元素
3. **不影响 size()**：只影响 capacity()
4. **防止重新分配**：如果 n > capacity()，会分配至少能容纳 n 个元素的内存

```cpp
std::vector<int> v = {1, 2, 3};
v.reserve(100);  // capacity至少为100，但size仍为3
```

## 关键区别

| 特性        | resize() | reserve() |
|------------|----------|-----------|
| 改变元素数量 | 是       | 否        |
| 改变size()  | 是       | 否        |
| 改变capacity() | 可能    | 是        |
| 添加/删除元素 | 可能    | 否        |

## 使用场景

- 用 `reserve()` 当你预先知道需要多少空间，避免多次重新分配
- 用 `resize()` 当你需要立即改变 vector 中元素的数量