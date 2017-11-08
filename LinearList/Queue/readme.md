# 排队或者队队列（Queue)
队列是对线性表的插入和删除操作加以限定的另一种限定性数据结构。

# 队列的定义
将线性表的插入和删除操作分别限制在表的两端进行，和栈相反，队列是一种先进先出（ First In First Out ， 简称  FIFO  结构）的线性表。![queue]()

# 队列的基本操作
Type 是队列中元素的类型
```C++ code
// 入队，成功true,否则false
bool EnQueue(const Type & data);

// 出队，成功true，否则false
bool DeQueue(void);

// 返回队首，如果队空，未定义。使用前应当判断队列
const Type & Front(void) const;

// 换一种方式返回队首，成功true，否则false
bool Front(Type & data) const;

// 队空，true，否则false
bool IsEmpty(void) const;

// 队满，true，否则false。
bool IsFull(void) const;

// 清空队列,重置首尾指针
void MakeNull(void);
```

# 队列的实现
存储和状态(空和满）表示

## 数组实现
使用数组来存储数据，使用两个下标值来分别表示队首和队尾。数组实现有两个关键点。一个关键是"假溢出"即当队尾指向了数组尾部，但是队列未满的情况。另外一个关键点是解决队状态的空和满的标识。
`.\array_queue\`

## 指针实现
链式结构存储，两个指针分别表示队首和队尾。
`.\link_queue\`

# 队列的应用场景或者原则
凡是符合先进先出原则的
## 应用举例
- 约瑟夫出圈问题
- 舞伴顺序匹配

# 队列的更多讨论
## 利用栈来模拟队列。设计一个结构，完成队列的功能，并高效的求解出队列中的最大值。
`.\stack_queue\`
