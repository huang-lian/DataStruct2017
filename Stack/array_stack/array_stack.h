// C++ file
/* 栈的数组实现
 * author:huang_lian@126.com
 * data:2017年10月19日 星期四
 **/
#ifndef ARRAY_STACK
#define ARRAY_STACK
template<class Type>
class ArrayStack {
  public:
    explicit ArrayStack(size_t n = 100);
    ~ArrayStack();
    
    bool Push(const Type & data);
    bool Pop(void);

    const Type & Top(void) const;
    // 应该检查是否为空后再使用
    
    bool Top(Type & data) const;

    bool IsEmpty(void) const;
    bool IsFull(void) const;

    void MakeNull(void) {top_ = 0;};
  private:
    size_t max_length_;
    size_t top_; // top_ 始终指向将要存放的位置
    Type * space_;
};

template<class Type>
ArrayStack<Type>::ArrayStack(size_t n) : max_length_(n), top_(0) {
  space_ = new Type[max_length_];
}

template<class Type>
ArrayStack<Type>::~ArrayStack(void) {
  delete [] space_;
}

template<class Type>
bool ArrayStack<Type>::Push(const Type & data) {
  if (IsFull())
    return false;
  space_[top_++] = data;
  return true;
}

template<class Type>
bool ArrayStack<Type>::Pop(void) {
  if (IsEmpty())
    return false;
  top_--;
  return true;
}

template<class Type>
const Type & ArrayStack<Type>::Top(void) const {
  // undefine if stack is empty 
  return space_[top_ - 1];
}

template<class Type>
bool ArrayStack<Type>::Top(Type & data) const {
  if (IsEmpty())
    return false;
  data = space_[top_ - 1];
  return true;
}

template<class Type>
bool ArrayStack<Type>::IsFull(void) const {
  return top_ == max_length_;
}

template<class Type>
bool ArrayStack<Type>::IsEmpty(void) const {
  return 0 == top_;
}
#endif // ARRAY_STACK
