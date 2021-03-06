# 堆(heap)
一种特殊形式的完全二叉树 —— 堆（ heap ）。
它有两种基本形式：最大堆和最小堆。
如果一棵完全二叉树的任意一个非终结结点的元素都不小于其左儿子结点和右儿子结点（如果有的话）的元素，则称此完全二叉树为最大堆。
类似地，如果一棵完全二叉树的任意一个非终结结点的元素都不大于其左儿子结点和右儿子结点（如果有的话）的元素，则称此完全二叉树为最小堆。

# 最大堆的操作
```C++ code
// 创建一个空堆
Heap::Heap(size\_t max_size);
// 最多可容纳 max_size 个元素。

// 置空堆
void Heap::MakeNull();

// 判断堆是否为满
bool Heap::IsFull(void) const;
// 若堆中元素个数达到最大容量 MaxSize ，则返回true，否则返回false。

// 判断堆是否为空
bool Heap::IsEmpty(void) const;
// 若堆中元素个数大于0 0 ，则返回 false，否则返回true。

// 插入一个元素
bool Heap::Insert(const Type & item );
// 。若堆不满，则将item 插入heap,true ，否则不能插入flase。

// 删除最大元素
bool Heap::Delete(void);
// 若堆为不空，并将其删除,true，否则，返回一个false，表明不能进行删除。

// 返回最大元素
const Type & Heap::Max(void) const;
// 若堆为不空，并将返回，否则未定义。

```
# 具体实现：堆的维护
始终需要保证堆是一棵[完全二叉树]()
  - 对于建立起来的完全二叉树插入和删除都是对最后一个叶节点操作即可
  - 可以保证不破坏树的结构，避免重新调整树结构

最大堆的parent 的值总是大于child的值.
- 删除
  - 1. 进行删除前，节点数据和最后一个叶节点数据交换．
  - 2. 删除最后一个叶节点，然后比较新的根节点和孩子的大小关系，
  - 3. 如果孩子大于根，交换父子．然后对发生交换的支进行3比较交换操作．
- 一个更加优化的方案是
  - 1,缓存最后一个叶节点，删除最后一个叶节点
  - 2,将缓存值视为父节点，和孩子比较，
    - 如果孩子较大，直接赋值给父节点．然后视缓存值为该发生交换支的父节点，进行2．
    - 否则将缓存值赋值给父节点

- 插入
- 新插入的数据作为最后一个叶的数据
- 该数据和父节点数据比较，
  - 较大，则交换父节点和该节点数据．继续向上比较．
  - 否则，插入完成
- 一个更加优化的方案
- 将新值视作已插入．到最后叶节点，
- 比较新值和父节点，
  - 新值较大，则将父节点值覆盖到新节点，视新值被覆盖给了父节点．然后继续向上比较．
  - 赋值新值，否则插入完成.

使用静态数组实现完全二叉树的(层序)顺序存储是更加容易且高效的．
- 更加容易插入和删除：不必每次操作前都需要查找最后一个叶节点以及其节点．(左右链式结构不方便保存这两个节点，每次插入和删除后，不容易确定最后一个叶节点的父节点）
- 利用数组中的元素索引数学关系代替指向父亲，孩子的指针．而且最后一个叶节点位置明确．

# 实现说明
由于最大堆和最小堆只是在插入和删除时候的大小关系调整了一下,其具体实现是高度相似的,这里只实现了最大堆.
另外,为了删除和获取最大值更加方便,这里实现以下两个接口.
```
// 删除最大元素
bool Heap::Delete(const Type & data);
// 若堆为不空,赋值给data,删除最大值,返回true，否则不修改data,返回false

// 返回最大元素
bool Heap::Max(const Type & data) const;
// 若堆为不空,赋值给data,返回true，否则不修改data,返回false
```
