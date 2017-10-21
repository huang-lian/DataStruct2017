// C++ file
/* 求解队列最值 
 * Author:huang_lian@126.com
 * date:2017年10月21日 星期六
 **/
#ifndef MAX_VALUE_QUEUE_H
#define MAX_VALUE_QUEUE_H
#include"../../Stack/link_stack/link_stack.h"
template<class Type>
class MaxValueQueue{
  public:
    MaxValueQueue(void);
    MaxValueQueue(const MaxValueQueue<Type> & stq);
    ~MaxValueQueue(void);

    const MaxValueQueue<Type> & operator=(const MaxValueQueue<Type> & stq);
    
    void MakeNull(void);

    // 入队，成功true,否则false
    bool EnQueue(const Type & data);

    // 出队，成功true，否则false
    bool DeQueue(void);

    // 返回队首，如果队空，未定义。使用前应当判断队列
    const Type & Front(void);

    // 换一种方式返回队首，成功true，否则false
    bool Front(Type & data);


    // 队空，true，否则false
    bool IsEmpty(void) const;

    // 队满，true，否则false。
    bool IsFull(void) const;

    const Type & MaxValue(void) const;
    bool MaxValue(Type & data);

  private:
    void set_max(const Type & data);
    void Balance(void);
    LinkStack<Type> st_in_;
    LinkStack<Type> st_out_;
    LinkStack<Type> st_max_;
};

template<class Type>
void MaxValueQueue<Type>::set_max(const Type & data) {
      if ((!st_max_.IsEmpty())&& st_max_.Top() > data) {
	st_max_.Push(st_max_.Top());
      } else {
	st_max_.Push(data);
      }
}

template<class Type>
void MaxValueQueue<Type>::Balance(void) {
  if (st_out_.IsEmpty()) {
    st_max_.MakeNull();
    while(!st_in_.IsEmpty()) {
      st_out_.Push(st_in_.Top());

      set_max(st_out_.Top());

      st_in_.Pop();
    }
  }
}
template<class Type>
MaxValueQueue<Type>::MaxValueQueue(void) {
}

template<class Type>
MaxValueQueue<Type>::MaxValueQueue(const MaxValueQueue<Type> & stq) {
  st_in_ = stq.st_in_;
  st_out_ = stq.st_out_;
  st_max_ = stq.st_max_;
  
}

template<class Type>
MaxValueQueue<Type>::~MaxValueQueue(void) {
}

template<class Type>
const MaxValueQueue<Type> & MaxValueQueue<Type>::operator=(const MaxValueQueue<Type> & stq) {
  st_in_ = stq.st_in_;
  st_out_ = stq.st_out_;
  st_max_ = stq.st_max_;
}

template<class Type>
void MaxValueQueue<Type>::MakeNull(void) {
  st_in_.MakeNull();
  st_out_.MakeNull();
  st_max_.MakeNull();
}
template<class Type>
bool MaxValueQueue<Type>::EnQueue(const Type & data) {
  if(IsFull())
    return false;
  st_in_.Push(data);
  set_max(st_in_.Top());
  return true;
}

template<class Type>
bool MaxValueQueue<Type>::DeQueue(void) {
  if (IsEmpty())
    return false;
  Balance();
  st_out_.Pop();
  st_max_.Pop();
  return true;
}

template<class Type>
const Type & MaxValueQueue<Type>::Front(void) {
  if (IsEmpty()) {
    Type zero;  // 避免出现段错误返回一个默认值
    return zero;
  }
  Balance();
  return st_out_.Top();
}

template<class Type>
bool MaxValueQueue<Type>::Front(Type & data) {
  if (IsEmpty())
    return false;
  Balance();
  data = st_out_.Top();
  return true;
}

template<class Type>
bool MaxValueQueue<Type>::IsEmpty(void) const {
  if (st_in_.IsEmpty() && st_out_.IsEmpty())
    return true;
  return false;
}

template<class Type>
bool MaxValueQueue<Type>::IsFull(void) const {
  if (st_in_.IsFull() || st_out_.IsFull())
    return true;
  return false;
}

template<class Type>
const Type & MaxValueQueue<Type>::MaxValue(void) const {
  if (!IsEmpty())
    return st_max_.Top();

  Type zero;
  return zero;
}
template<class Type>
bool MaxValueQueue<Type>::MaxValue(Type & data) {
  return st_max_.Top(data);
}
#endif // MAX_VALUE_QUEUE_H
