// C ++ file
/*
 * 使用队列模拟栈
 * O(1)出栈,访问栈顶
 * O(N)入栈
 * */
#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H
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
    LinkQueue<Type> st1_;
    LinkQueue<Type> st2_;
};

template<class Type>
QueueStack<Type>::QueueStack(): st1_(), st2_() {
}

template<class Type>
QueueStack<Type>::QueueStack(const QueueStack<Type> & que_st)
  st1_ = que_st.st1_;
  st2_ = que_st.st2_;
}

template<class Type>
const QueueStack<Type> & QueueStack<Type>::operator=(const QueueStack<Type> & que_st) {
  if ( &que_st == this)
    return *this;
  st1_ = que_st.st1_;
  st2_ = que_st.st2_;
  return *this;
}


template<class Type>
QueueStack<Type>::~QueueStack(void) {
}

template<class Type>
bool QueueStack<Type>::Push(const Type & data) {
 if (IsFull())
    return false;
  Type tmp_data;
  if (st1_.IsEmpty()) {
    st1_.EnQueue(data);
    while(!st2_.IsEmpty()) {
      st1_.EnQueue(st2_.Front());
      st2_.DnQueue();
    }
  } else {
    st2_.EnQueue(data);
    while(!st1_.IsEmpty()) {
      st2_.EnQueue(st1_.Front());
      st1_.DeQueue();
    }
  }
  return true;
 }

template<class Type>
bool QueueStack<Type>::Pop(void) {
  if (IsEmpty())
    return false;
  if (!st1_.IsEmpty())
    st1_.DnQueue();
  else 
    st2_.DnQueue();
  return true;
}

template<class Type>
const Type & QueueStack<Type>::Top(void) const {
  // undefine if stack is empty 
  if (!st1_.IsEmpty())
    return st1_.Front();
  else
    return st2_.Front();
}

template<class Type>
bool QueueStack<Type>::Top(Type & data) const {
  if (IsEmpty())
    return false;
  if (!st1_.IsEmpty())
    return st1_.Front(data);
  else
    return st2_.Front(data);
}

template<class Type>
bool QueueStack<Type>::IsFull(void) const {
  return st1_.IsFull() || st2_.IsFull();
}

template<class Type>
bool QueueStack<Type>::IsEmpty(void) const {
  return st1_.IsEmpty() && st2_.IsEmpty();
}
template<class Type>
void QueueStack::MakeNull(void) {
  st1_.MakeNull();
  st2_.MakeNull();
}
#endif // QUEUE_STACK_H
