#ifndef QUEUE_STACK
#define QUEUE_STACK
#include"../link_queue/link_queue.h"
template<class Type>
class QueueStack {
  public:
    explicit QueueStack(void);
    QueueStack(const QueueStack<Type> & que_st);
    // 为了保证通用性实现

    ~QueueStack(void);

    const QueueStack<Type> & operator=(const QueueStack<Type> & que_st);
    
    bool Push(const Type & data);
    bool Pop(void);

    const Type & Top(void) const;
    // 应该检查是否为空后再使用
    
    bool Top(Type & data) const;

    bool IsEmpty(void) const;
    bool IsFull(void) const;

    void MakeNull(void);
  private:
    LinkQueue<Type> que_st1_;
    LinkQueue<Type> que_st2_;
};

template<class Type>
QueueStack<Type>::QueueStack(): que_st1_(), que_st2_() {
}

template<class Type>
QueueStack<Type>::QueueStack(const QueueStack<Type> & que_st)
  que_st1_ = que_st.que_st1_;
  que_st2_ = que_st.que_st2_;
}

template<class Type>
const QueueStack<Type> & QueueStack<Type>::operator=(const QueueStack<Type> & que_st) {
  if ( &que_st == this)
    return *this;
  que_st1_ = que_st.que_st1_;
  que_st2_ = que_st.que_st2_;
  return *this;
}


template<class Type>
QueueStack<Type>::~QueueStack(void) {
}

template<class Type>
bool QueueStack<Type>::Push(const Type & data) {
  if (IsFull())
    return false;
  if (!que_st1_.IsEmpty())
    que_st1_.Push(data);
  else if (!que_st2_.IsEmpty())
    que_st2_.Push(data);
  else
    que_st1_.Push(data);
  return true;
}

template<class Type>
bool QueueStack<Type>::Pop(void) {
  if (IsEmpty())
    return false;
  // #working
      return true;
}

template<class Type>
const Type & QueueStack<Type>::Top(void) const {
  // undefine if stack is empty 
  return space_[top_ - 1];
}

template<class Type>
bool QueueStack<Type>::Top(Type & data) const {
  if (IsEmpty())
    return false;
  data = space_[top_ - 1];
  return true;
}

template<class Type>
bool QueueStack<Type>::IsFull(void) const {
  return que_st1_.IsFull() || que_st2_.IsFull();
}

template<class Type>
bool QueueStack<Type>::IsEmpty(void) const {
  return que_st1_.IsEmpty() && que_st2_.IsEmpty();
}
#endif // QUEUE_STACK
