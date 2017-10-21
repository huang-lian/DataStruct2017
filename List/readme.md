# 线性表(LIST)
线性表是由 n(n≥0) 个相同类型的元素组成的有序集合
n为线性表的元素个数,也叫作线性表的长度.当n=0 时表为空表. 线性表有限且是有序的.

# 相关名称
- 前驱
- 后继

# 基本操作
设L 的型为LIST 线性表实例，x  的型为elementtype 的元素实例，pos  为位置变量。
所有操作描述为
```C++ code
void MakeNull(void);

bool Insert(Type & x, size_t pos);
bool Delete(size_t pos);

size_t Locate(Type & x);
const Type & Retrieve(size_t pos);

const Type & Previous(size_t pos);
const Type & Next(siz_t pos);
const Type & First(void);
const Type & End(void);

//Deleval(Type &x) 删除值为x的全部元素
```

# 线性表的实现

存储结构的三种方式：
1.  连续的存储空间（数组） → 静态存储
2.  非连续存储空间—— 指针（链表） → 动态存储
3.  游标（连续存储空间+ 动态管理思想）→ 静态链表
