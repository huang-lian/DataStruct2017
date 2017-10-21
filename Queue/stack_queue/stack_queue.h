// C++ file
/* 数组队列
 * Author:huang_lian@126.com
 * date:2017年10月21日 星期六
 **/
#ifndef STACKQUEUE_H
#define STACKQUEUE_H
#include"../../Stack/link_stack/link_stack.h"
template<class Type>
class StackQueue{
  public:
    StackQueue(void);
    StackQueue(const StackQueue<Type> & st_q);
    ~StackQueue(void);

    const StackQueue<Type> & operator=(const StackQueue<Type> & st_q);
    
    // 清空队列,重置首尾指针
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

  private:
    void Balance(void);
    LinkStack<Type> st_in_;
    LinkStack<Type> st_out_;

};
template<class Type>
void StackQueue<Type>::Balance(void) {
  if (st_out_.IsEmpty()) {
    while(!st_in_.IsEmpty()) {
      st_out_.Push(st_in_.Top());
      st_in_.Pop();
    }
  }
}


template<class Type>
StackQueue<Type>::StackQueue() {
}

template<class Type>
StackQueue<Type>::StackQueue(const StackQueue<Type> & st_q) {
  st_in_ = st_q.st_in_;
  st_out_ = st_q.st_out_;
}

template<class Type>
StackQueue<Type>::~StackQueue(void) {
}

template<class Type>
const StackQueue<Type> & StackQueue<Type>::operator=(const StackQueue<Type> & st_q) {
  st_in_ = st_q.st_in_;
  st_out_ = st_q.st_out_;
}

template<class Type>
void StackQueue<Type>::MakeNull(void) {
  st_in_.MakeNull();
  st_out_.MakeNull();
}
template<class Type>
bool StackQueue<Type>::EnQueue(const Type & data) {
  if(IsFull())
    return false;
  st_in_.Push(data);
  return true;
}

template<class Type>
bool StackQueue<Type>::DeQueue(void) {
  if (IsEmpty())
    return false;
  Balance();
  st_out_.Pop();
  return true;
}

template<class Type>
const Type & StackQueue<Type>::Front(void) {
  if (IsEmpty()) {
    Type zero;  // 避免出现段错误返回一个默认值
    return zero;
  }
  Balance();
  return st_out_.Top();
}

template<class Type>
bool StackQueue<Type>::Front(Type & data) {
  if (IsEmpty())
    return false;
  Balance();
  data = st_out_.Top();
  return true;
}

template<class Type>
bool StackQueue<Type>::IsEmpty(void) const {
  if (st_in_.IsEmpty() && st_out_.IsEmpty())
    return true;
  return false;
}

template<class Type>
bool StackQueue<Type>::IsFull(void) const {
  if (st_in_.IsFull() || st_out_.IsFull())
    return true;
  return false;
}
#endif // STACKQUEUE_H
