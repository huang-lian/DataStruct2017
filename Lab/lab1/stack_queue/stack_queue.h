// C++ file
/* 数组队列
 * Author:huang_lian@126.com
 * date:2017年10月21日 星期六
 **/
#ifndef STACKQUEUE_H
#define STACKQUEUE_H
#include"link_stack.h"
template<class Type>
class StackQueue{
  public:
    StackQueue(void);
    StackQueue(const StackQueue<Type> & stq);
    ~StackQueue(void);

    const StackQueue<Type> & operator=(const StackQueue<Type> & stq);
    
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
    LinkStack<Type> stin_;
    LinkStack<Type> stout_;

};

template<class Type>
StackQueue<Type>::StackQueue() {
}

template<class Type>
StackQueue<Type>::StackQueue(const StackQueue<Type> & stq) {
  stin_ = stq.stin_;
  stout_ = stq.stout_;
}

template<class Type>
StackQueue<Type>::~StackQueue(void) {
}

template<class Type>
const StackQueue<Type> & StackQueue<Type>::operator=(const StackQueue<Type> & stq) {
  stin_ = stq.stin_;
  stout_ = stq.stout_;
}

template<class Type>
void StackQueue<Type>::MakeNull(void) {
  stin_.MakeNull();
  stout_.MakeNull();
}
template<class Type>
bool StackQueue<Type>::EnQueue(const Type & data) {
  if(IsFull()) {
    return false;
  }
  stin_.Push(data);
  return true;
}

template<class Type>
bool StackQueue<Type>::DeQueue(void) {
  if (IsEmpty())
    return false;
  if (stout_.IsEmpty())
    while(!stin_.IsEmpty()) {
      stout_.Push(stin_.Top());
      stin_.Pop();
    }
  stout_.Pop();
  return true;
}

template<class Type>
const Type & StackQueue<Type>::Front(void) {
  if (stout_.IsEmpty())
    while(!stin_.IsEmpty()) {
      stout_.Push(stin_.Top());
      stin_.Pop();
    }
  return stout_.Top();
}

template<class Type>
bool StackQueue<Type>::Front(Type & data) {
  if (IsEmpty())
    return false;
  if (stout_.IsEmpty())
    while(!stin_.IsEmpty()) {
      stout_.Push(stin_.Top());
      stin_.Pop();
    }
  return stout_.Top(data);
}

template<class Type>
bool StackQueue<Type>::IsEmpty(void) const {
  if (stin_.IsEmpty() && stout_.IsEmpty())
    return true;
  return false;
}

template<class Type>
bool StackQueue<Type>::IsFull(void) const {
  if (stin_.IsFull() || stout_.IsFull())
    return true;
  return false;
}
#endif // STACKQUEUE_H
