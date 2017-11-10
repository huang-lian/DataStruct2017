// C++ file
/* 最大值栈
 * 没使用计数变量，而是保存相同值
 * author:huang_lian@126.com
 * date:2017年10月19日 星期四
 **/
#ifndef MAX_VALUE_STACK
#define MAX_VALUE_STACK
#include"../share_stack/share_stack.h"
template<class Type>
class MaxValueStack{
  public:
    MaxValueStack(void);
    ~MaxValueStack(void);
    bool Push(const Type & data);
    bool Pop(void);

    const Type & Top(void) const;
    // 应该检查是否为空后再使用

    bool Top(Type & data) const;

    const Type & MaxValue(void) const;
    bool MaxValue(Type & data) const;

    bool IsEmpty(void) const;
    bool IsFull(void) const;

    void ShowStack(void) const;
  private:
    ShareStack<Type> values_;
    ShareStack<Type> max_value_;
};
template<class Type>
MaxValueStack<Type>::MaxValueStack(void) : values_(), max_value_(){
}

template<class Type>
MaxValueStack<Type>::~MaxValueStack(void){
}

template<class Type>
bool MaxValueStack<Type>::Push(const Type & data) {
  if (!values_.Push(data)) return false;
  if (IsEmpty()) {
    if(!max_value_.Push(data)) {
      values_.Pop(); // 保持栈高度一致性
      return false; 
    }
  } else if (data > max_value_.Top()) {
    if(!max_value_.Push(data)) {
      values_.Pop(); // 保持栈高度一致性
      return false; 
    }
  } else if(!max_value_.Push(max_value_.Top())) {
    values_.Pop(); // 保持栈高度一致性
    return false;
  } 
  return true;
}

template<class Type>
bool MaxValueStack<Type>::Pop(void) {
  return (values_.Pop() && max_value_.Pop());  // 存入时候高度一致，弹出也是一致的
}

template<class Type>
const Type & MaxValueStack<Type>::Top(void) const {
  return values_.Top();
}

template<class Type>
bool MaxValueStack<Type>::Top(Type & data) const {
  return values_.Top(data);
}

template<class Type>
const Type & MaxValueStack<Type>::MaxValue(void) const {
  return max_value_.Top();
}

template<class Type>
bool MaxValueStack<Type>::MaxValue(Type & data) const {
  return max_value_.Top(data);
}

template<class Type>
bool MaxValueStack<Type>::IsEmpty(void) const {
  return values_.IsEmpty() && max_value_.IsEmpty();
}

template<class Type>
bool MaxValueStack<Type>::IsFull(void) const{
  return values_.IsFull() && max_value_.IsFull();
}

template<class Type>
void MaxValueStack<Type>::ShowStack(void) const {
  std::cout << "===##ShowStack Start###===\nIn Values Stack\n";
  values_.ShowStack();
  std::cout << "-------------------------\nIn MaxValue Stack\n";
  max_value_.ShowStack();
  std::cout << "====##ShowStack End##======\n";
}
#endif // MAX_VALUE_STACK
