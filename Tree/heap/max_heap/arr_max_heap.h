// 数组形式的大根堆

#ifndef ARR_MAX_HEAP_H 
#define ARR_MAX_HEAP_H
#define ARR_MAX_HEAP_MAXSIZE  200 
template<class Type>
class ArrMaxHeap{
  public:
    ArrMaxHeap(size_t kMaxSize = ARR_MAX_HEAP_MAXSIZE);
    ArrMaxHeap(const ArrMaxHeap & maxhp):
      const ArrMaxHeap & operator=(const ArrMaxHeap & maxhp);
    ~ArrMaxHeap(void);

    void MakeNull();
    bool Insert(const Type & data);
    bool Delete(void);
    bool Delete(Type & data);

    const Type & Max(void) const;
    bool Max(Type & data) const;

    bool IsEmpty(void);
    bool IsFull(void);

    size_t size(void);
  private:
    struct HeapNode{
      Type data;
    }
    size_t　max_size_;
    size_t index;
    HeapNode * root_;
};

  template<class Type>
ArrMaxHeap::ArrMaxHeap(size_t kMaxSize = ARR_MAX_HEAP_MAXSIZE)
{ 
  max_size_ = kMaxSize;
  index = 0;
  root_ = new HeapNode[kMaxSize];
}

  template<class Type>
ArrMaxHeap::ArrMaxHeap(const ArrMaxHeap & maxhp) : max_size_(maxhp.max_size_)
{
  // #pass
}

  template<class Type>
ArrMaxHeap::const ArrMaxHeap & operator=(const ArrMaxHeap & maxhp)
{
  // #pass
}

  template<class Type>
ArrMaxHeap::~ArrMaxHeap(void)
{
  // #pass
}


  template<class Type>
void ArrMaxHeap::MakeNull()
{
  // #pass
}

  template<class Type>
bool ArrMaxHeap::Insert(const Type & data)
{
  // #pass
}

  template<class Type>
bool ArrMaxHeap::Delete(void)
{
  // #pass
}

  template<class Type>
bool ArrMaxHeap::Delete(Type & data)
{
  // #pass
}


template<class Type>
const Type & ArrMaxHeap::Max(void) const
{
  // #pass
}

template<class Type>
bool ArrMaxHeap::Max(Type & data) const
{
  // #pass
}


  template<class Type>
bool ArrMaxHeap::IsEmpty(void)
{
  // #pass
}

  template<class Type>
bool ArrMaxHeap::IsFull(void)
{
  // #pass
}


  template<class Type>
size_t ArrMaxHeap::size(void)
{
  // #pass
}
#endif // ARR_MAX_HEAP_H
