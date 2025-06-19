# `priority_queue` 容器适配器的使用详解

`priority_queue` 是 C++ STL 中的一种容器适配器，它提供了一种优先级队列的实现，允许元素按照特定的优先级顺序被访问（默认是最大元素优先）。

## 基本概念

`priority_queue` 是一个容器适配器，它基于底层容器（默认是 `vector`）和堆算法实现，具有以下特点：
- 每次访问的是优先级最高的元素
- 插入操作会自动维护优先级顺序
- 默认是大顶堆（最大元素优先）

## 典型使用场景：医院急诊分诊系统

让我们用一个医院急诊分诊系统的例子来详细说明 `priority_queue` 的使用。

### 场景描述

医院急诊科需要根据患者病情的紧急程度来决定就诊顺序：
1. 危重病人（优先级1）最先就诊
2. 急症病人（优先级2）次之
3. 普通病人（优先级3）最后

### 实现代码

```cpp
#include <iostream>
#include <queue>
#include <string>

// 病人结构体
struct Patient {
    std::string name;
    int priority;  // 1: 危重, 2: 急症, 3: 普通
    std::string symptom;
    
    // 构造函数
    Patient(std::string n, int p, std::string s) 
        : name(n), priority(p), symptom(s) {}
};

// 自定义比较函数，priority值小的优先级高
struct ComparePatient {
    bool operator()(const Patient& a, const Patient& b) {
        return a.priority > b.priority;  // 小顶堆
    }
};

int main() {
    // 创建优先队列，使用自定义比较函数
    std::priority_queue<Patient, std::vector<Patient>, ComparePatient> emergencyQueue;
    
    // 添加病人到队列
    emergencyQueue.push(Patient("张三", 2, "急性腹痛"));
    emergencyQueue.push(Patient("李四", 1, "心脏骤停"));
    emergencyQueue.push(Patient("王五", 3, "轻微擦伤"));
    emergencyQueue.push(Patient("赵六", 1, "严重外伤"));
    emergencyQueue.push(Patient("钱七", 2, "高烧不退"));
    
    // 模拟就诊过程
    std::cout << "急诊就诊顺序：" << std::endl;
    while (!emergencyQueue.empty()) {
        Patient current = emergencyQueue.top();
        std::cout << "正在就诊: " << current.name 
                  << " (优先级:" << current.priority 
                  << ", 症状:" << current.symptom << ")" << std::endl;
        emergencyQueue.pop();
    }
    
    return 0;
}
```

### 输出结果

```
急诊就诊顺序：
正在就诊: 李四 (优先级:1, 症状:心脏骤停)
正在就诊: 赵六 (优先级:1, 症状:严重外伤)
正在就诊: 张三 (优先级:2, 症状:急性腹痛)
正在就诊: 钱七 (优先级:2, 症状:高烧不退)
正在就诊: 王五 (优先级:3, 症状:轻微擦伤)
```

### 代码解析

1. **自定义数据结构**：我们定义了 `Patient` 结构体来存储病人信息。

2. **比较函数**：通过 `ComparePatient` 结构体定义了优先级比较规则，这里我们使用小顶堆（priority值小的优先级高）。

3. **创建优先队列**：
   ```cpp
   std::priority_queue<Patient, std::vector<Patient>, ComparePatient> emergencyQueue;
   ```
   - 第一个模板参数：存储的元素类型（Patient）
   - 第二个模板参数：底层容器类型（默认vector）
   - 第三个模板参数：比较函数类型

4. **添加元素**：使用 `push()` 方法添加病人到队列。

5. **访问元素**：使用 `top()` 方法获取优先级最高的病人。

6. **移除元素**：使用 `pop()` 方法移除已就诊的病人。

## 其他常见使用场景

1. **任务调度系统**：高优先级任务先执行
2. **Dijkstra算法**：用于图的最短路径计算
3. **Huffman编码**：用于数据压缩
4. **事件驱动模拟**：按时间顺序处理事件

## 注意事项

1. **默认是大顶堆**：如果不提供比较函数，默认是最大元素优先。

2. **自定义比较函数**：如果需要最小元素优先或其他排序规则，必须提供自定义比较函数。

3. **底层容器**：默认使用 `vector`，但也可以使用 `deque`。

4. **没有迭代器**：不能像其他容器那样遍历 `priority_queue`。

5. **时间复杂度**：
   - 插入操作（push）：O(log n)
   - 访问顶部元素（top）：O(1)
   - 删除顶部元素（pop）：O(log n)

通过这个例子，你应该能够理解 `priority_queue` 的基本用法和适用场景。在实际开发中，它非常适合需要按优先级处理元素的场景。