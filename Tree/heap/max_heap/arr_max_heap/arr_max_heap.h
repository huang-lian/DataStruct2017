// 数组形式的大根堆

#ifndef ARR_MAX_HEAP_H 
#define ARR_MAX_HEAP_H
#define ARR_MAX_HEAP_MAXSIZE  200 
template<class Type>
class ArrMaxHeap{
  public:
    ArrMaxHeap(size_t kMaxSize = ARR_MAX_HEAP_MAXSIZE);
    ArrMaxHeap(const ArrMaxHeap & maxhp);
      const ArrMaxHeap & operator=(const ArrMaxHeap & maxhp);
    ~ArrMaxHeap(void);

    void MakeNull();
    bool Insert(const Type & data);
    bool Delete(void);
    bool Delete(Type & data);

    const Type & Max(void) const;
    bool Max(Type & data) const;

    bool IsEmpty(void) const;
    bool IsFull(void) const;

    size_t size(void);
  private:
    struct HeapNode {
      Type data;
    };
    size_t max_size_;
    size_t size_;
    HeapNode * root_;
};

  template<class Type>
ArrMaxHeap<Type>::ArrMaxHeap(size_t kMaxSize)
{ 
  max_size_ = kMaxSize;
  size_ = 0;
  root_ = new HeapNode[kMaxSize];
}

  template<class Type>
ArrMaxHeap<Type>::ArrMaxHeap(const ArrMaxHeap<Type> & maxhp) : max_size_(maxhp.max_size_)
{
  root_ = new HeapNode[0];
  *this = maxhp;
}

  template<class Type>
const ArrMaxHeap<Type> & ArrMaxHeap<Type>::operator=(const ArrMaxHeap & maxhp)
{
  if (&maxhp == this)
    return *this;
  delete [] root_;
  max_size_ = maxhp.max_size_;
  size_ = maxhp.size_;
  root_ = new HeapNode[max_size_];
  for(size_t i = 0; i <= size_; i++)
    root_[i] = maxhp.root_[i];
  return *this;
}

  template<class Type>
ArrMaxHeap<Type>::~ArrMaxHeap(void)
{
  delete [] root_;
}


  template<class Type>
void ArrMaxHeap<Type>::MakeNull()
{
  size_ = 0;
}

  template<class Type>
bool ArrMaxHeap<Type>::Insert(const Type & data)
{
  size_t i;
  if (IsFull())
    return false;
  size_++;
  i = size_;

  // 新数据默认插在最后,和父节点比较，如果大于父节点．则父节点下移
  // 最后获得一个位置用于存放数据
  while((1 != i) && (root_[i/2].data < data)) {
    root_[i].data = root_[i/2].data;
    i = i/2;
  }
  root_[i].data = data;
  return true;
}

  template<class Type>
bool ArrMaxHeap<Type>::Delete(void)
{
  if(IsEmpty())
    return false;

  // 缓存最后一个叶节点数据
  // 删除最后一个叶节点,保证树结构，调整树结构
  Type tmp = root_[size_].data;
  size_--;
  size_t parent = 1, child = 2;
  while(child <= size_) {

    // 比较左右两个节点，父节点保留较大值
    if ((child < size_) && (root_[child].data < root_[child + 1].data)) {
      child ++;
    }
    if(tmp >= root_[child].data) break;
    root_[parent].data = root_[child].data;

    // 进入较大支
    parent = child;
    child *= 2; // 访问右儿子
  }
  root_[parent].data = tmp;
  return true;
}

  template<class Type>
bool ArrMaxHeap<Type>::Delete(Type & data)
{
  if(IsEmpty())
  return false;
  data = root_[1].data;
  return Delete();
}


template<class Type>
const Type & ArrMaxHeap<Type>::Max(void) const
{
  return root_[1].data;
}

template<class Type>
bool ArrMaxHeap<Type>::Max(Type & data) const
{
  if(IsEmpty())
    return false;
  data = root_[1].data;
  return true;
}


  template<class Type>
bool ArrMaxHeap<Type>::IsEmpty(void) const
{
  return 0 == size_;
}

  template<class Type>
bool ArrMaxHeap<Type>::IsFull(void) const
{
  return max_size_== size_;
}


  template<class Type>
size_t ArrMaxHeap<Type>::size(void)
{
  return size_;
}
#endif // ARR_MAX_HEAP_H
