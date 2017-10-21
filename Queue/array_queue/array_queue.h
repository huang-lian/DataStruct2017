// C++ file
/* 数组队列
 * Author:huang_lian@126.com
 * date:2017年10月21日 星期六
 **/
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#define ARRAY_QUEUE_MAX_SIZE 100
template<class Type>
class ArrayQueue{
  public:
    ArrayQueue(size_t max_size = ARRAY_QUEUE_MAX_SIZE);
    ArrayQueue(const ArrayQueue<Type> & arr_q);
    ~ArrayQueue(void);

    const ArrayQueue<Type> & operator=(const ArrayQueue<Type> & arr_q);
    
    // 清空队列,重置首尾指针
    void MakeNull(void);

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

  private:
    // 实现循环的关键
    size_t Inc(size_t n) const {return (n + 1) % max_size_;};
    size_t max_size_;
    size_t front_;
    size_t rear_;
    Type * space_;
};

template<class Type>
ArrayQueue<Type>::ArrayQueue(size_t max_size) : max_size_(max_size) {
  front_ = max_size_ - 1;
  rear_ = 0;
  space_ = new Type[max_size_];
}

template<class Type>
ArrayQueue<Type>::ArrayQueue(const ArrayQueue<Type> & arr_q) {
  max_size_ = arr_q.max_size_;
  front_ = arr_q.front_;
  rear_ = arr_q.rear_;
  space_ = new Type[max_size_];
  for(size_t i = 0; i < max_size_; i ++) {
    space_[i] = arr_q.space_[i];
  }
}

template<class Type>
ArrayQueue<Type>::~ArrayQueue(void) {
  if (NULL != space_)
    delete [] space_;
}

template<class Type>
const ArrayQueue<Type> & ArrayQueue<Type>::operator=(const ArrayQueue<Type> & arr_q) {
  if (&arr_q == this)
    return *this;

  delete [] space_;
  max_size_ = arr_q.max_size_;
  front_ = arr_q.front_;
  rear_ = arr_q.rear_;
  space_ = new Type[max_size_];

  for(size_t i = 0; i < max_size_; i ++) {
    space_[i] = arr_q.space_[i];
  }

}

template<class Type>
void ArrayQueue<Type>::MakeNull(void) {
  front_ = max_size_ -1;
  rear_ = 0;
}
template<class Type>
bool ArrayQueue<Type>::EnQueue(const Type & data) {
  if (IsFull())
    return false;

  space_[rear_] = data;
  rear_ = Inc(rear_);

  return true;
}

template<class Type>
bool ArrayQueue<Type>::DeQueue(void) {
  if (IsEmpty())
    return false;
  front_ = Inc(front_);
  return true;
}

template<class Type>
const Type & ArrayQueue<Type>::Front(void) const {
  if (!IsEmpty())
    return space_[front_];
  Type zero;  // 避免出现段错误返回一个默认值
  return zero;
}

template<class Type>
bool ArrayQueue<Type>::Front(Type & data) const  {
  if (IsEmpty())
    return false;
  data = space_[front_];
  return true;
}

template<class Type>
bool ArrayQueue<Type>::IsEmpty(void) const {
  if (Inc(front_) == rear_)
    return true;
  return false;
}

template<class Type>
bool ArrayQueue<Type>::IsFull(void) const {
  if (rear_ == front_)
    return true;
  return false;
}
#endif // ARRAYQUEUE_H
