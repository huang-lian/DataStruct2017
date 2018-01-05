// 数组形式的大根堆

#ifndef ARR_MIN_HEAP_H 
#define ARR_MIN_HEAP_H
#define ARR_MIN_HEAP_MINSIZE  200 
template<class Type>
class ArrMinHeap{
  public:
    ArrMinHeap(size_t kMinSize = ARR_MIN_HEAP_MINSIZE);
    ArrMinHeap(const ArrMinHeap & minhp);
      const ArrMinHeap & operator=(const ArrMinHeap & minhp);
    ~ArrMinHeap(void);

    void MakeNull();
    bool Insert(const Type & data);
    bool Delete(void);
    bool Delete(Type & data);

    const Type & Min(void) const;
    bool Min(Type & data) const;

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
ArrMinHeap<Type>::ArrMinHeap(size_t kMinSize)
{ 
  max_size_ = kMinSize;
  size_ = 0;
  root_ = new HeapNode[kMinSize];
}

  template<class Type>
ArrMinHeap<Type>::ArrMinHeap(const ArrMinHeap<Type> & minhp) : max_size_(minhp.max_size_)
{
  root_ = new HeapNode[0];
  *this = minhp;
}

  template<class Type>
const ArrMinHeap<Type> & ArrMinHeap<Type>::operator=(const ArrMinHeap & minhp)
{
  if (&minhp == this)
    return *this;
  delete [] root_;
  max_size_ = minhp.max_size_;
  size_ = minhp.size_;
  root_ = new HeapNode[max_size_];
  for(size_t i = 0; i <= size_; i++)
    root_[i] = minhp.root_[i];
  return *this;
}

  template<class Type>
ArrMinHeap<Type>::~ArrMinHeap(void)
{
  delete [] root_;
}


  template<class Type>
void ArrMinHeap<Type>::MakeNull()
{
  size_ = 0;
}

  template<class Type>
bool ArrMinHeap<Type>::Insert(const Type & data)
{
  size_t i;
  if (IsFull())
    return false;
  size_++;
  i = size_;

  // 新数据默认插在最后,和父节点比较，如果小于父节点．则父节点下移
  // 最后获得一个位置用于存放数据
  //while((1 != i) && (root_[i/2].data < data)) {
  while((1 != i) && (data < root_[i/2].data)) {
    root_[i].data = root_[i/2].data;
    i = i/2;
  }
  root_[i].data = data;
  return true;
}

  template<class Type>
bool ArrMinHeap<Type>::Delete(void)
{
  if(IsEmpty())
    return false;

  // 缓存最后一个叶节点数据
  // 删除最后一个叶节点,保证树结构，调整树结构
  Type tmp = root_[size_].data;
  size_--;
  size_t parent = 1, child = 2;
  while(child <= size_) {

    // 比较左右两个节点，父节点保留较小值
    //if ((child < size_) && (root_[child].data < root_[child + 1].data)) {
    if ((child < size_) && (root_[child + 1].data < root_[child].data )) {
      child ++;
    }
    //if(tmp >= root_[child].data) break;
    //if(!(tmp < root_[child].data)) break;
    if(!(root_[child].data < tmp ))break;
    root_[parent].data = root_[child].data;

    // 进入较小支
    parent = child;
    child *= 2; // 访问右儿子
  }
  root_[parent].data = tmp;
  return true;
}

  template<class Type>
bool ArrMinHeap<Type>::Delete(Type & data)
{
  if(IsEmpty())
  return false;
  data = root_[1].data;
  return Delete();
}


template<class Type>
const Type & ArrMinHeap<Type>::Min(void) const
{
  return root_[1].data;
}

template<class Type>
bool ArrMinHeap<Type>::Min(Type & data) const
{
  if(IsEmpty())
    return false;
  data = root_[1].data;
  return true;
}


  template<class Type>
bool ArrMinHeap<Type>::IsEmpty(void) const
{
  return 0 == size_;
}

  template<class Type>
bool ArrMinHeap<Type>::IsFull(void) const
{
  return max_size_== size_;
}


  template<class Type>
size_t ArrMinHeap<Type>::size(void)
{
  return size_;
}
#endif // ARR_MIN_HEAP_H
