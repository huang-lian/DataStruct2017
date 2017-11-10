/* * 链式结构的大根堆（应当存在限制大小的大根堆，数组形式） * */
#ifndef MAX_HEAP_H 
#define MAX_HEAP_H
template<class Type>
class MaxHeap{
  public:
    MaxHeap(void);
    MaxHeap(const MaxHeap & maxhp):
    const MaxHeap & operator=(const MaxHeap & maxhp);
    ~MaxHeap(void);

    void MakeNull();
    bool Insert(const Type & data);
    bool Delete(void);
    bool Delete(Type & data);

    const Type & Max(void) const;
    bool Max(Type & data) const;

    bool IsEmpty(void);
    bool IsFull(void);

    bool operator==(const MaxHeap & maxhp);
    
    size_t size(void);
  private:
    // ...
};
#endif // MAX_HEAP_H
