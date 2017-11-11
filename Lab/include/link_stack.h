// C++ file
/* 链式结构实现栈
 * author：huang_lian@126.com
 * date:2017年10月18日20:32:40
 **/
#ifndef LINK_STACK
#define LINK_STACK
template<class Type>
class LinkStack{
  public:
    LinkStack(void);
    LinkStack(const LinkStack<Type> & lk_st);
    ~LinkStack(void);
    const LinkStack<Type> & operator=(const LinkStack<Type> & lk_st);

    void MakeNull(void); 
    // 本函数和析构函数相关，放置在此

    bool Push(const Type & data);
    bool Pop(void);

    const Type & Top(void) const;
    // 应该检查是否为空后再使用

    bool Top(Type & data) const;

    bool IsEmpty(void) const;

    bool IsFull(void) const;
    // 对于动态类型的，空的判断是否是不必要的
    // 但是还是对于内存耗尽保持怀疑， 

  private: 
    struct Element{
      Type data;
      struct Element * next;
    };
    Element * top_;
};

template<class Type>
LinkStack<Type>::LinkStack(void) :top_(0) {
}

template<class Type>
LinkStack<Type>::LinkStack(const LinkStack<Type> & lk_st) {
  Element *p = top_;
  Element *pre = NULL;
  Element *newnode = NULL;

  if (NULL != p) {
    newnode = new Element;   // #fix #Q 此处new失败该如何处理
    newnode->data = p->data;

    lk_st.top_ = newnode;
    pre = newnode;
    p = p->next;
  }
  
  for(; NULL != p; p = p->next) {
    newnode = new Element;   // #fix #Q 此处new失败该如何处理
    newnode->data = p->data;

    pre->next = newnode;
    
    pre = newnode;
  }
  if(NULL != pre)
  pre->next = NULL;
}

template<class Type>
const LinkStack<Type> & LinkStack<Type>::operator=(const LinkStack<Type> & lk_st) {
  if (&lk_st == this)
    return *this;
  MakeNull();
  Element *p = lk_st.top_;
  Element *pre = NULL;
  Element *newnode = NULL;

  if (NULL != p) {
    newnode = new Element;   // #fix #Q 此处new失败该如何处理
    newnode->data = p->data;

    top_ = newnode;
    pre = newnode;
    p = p->next;
  }
  
  for(; NULL != p; p = p->next) {
    newnode = new Element;   // #fix #Q 此处new失败该如何处理
    newnode->data = p->data;

    pre->next = newnode;
    
    pre = newnode;
  }

  if (NULL != pre)
  pre->next = NULL;

  return *this;
}

template<class Type>
LinkStack<Type>::~LinkStack(void) {
  MakeNull();
}

template<class Type>
void LinkStack<Type>::MakeNull(void) {
  Element *p = top_;
  while(NULL != top_) {
    p = top_;
    top_ = top_->next;
    delete p;
  }
}

template<class Type>
bool LinkStack<Type>::Push(const Type & data) {
  Element *p = NULL;
  try {                 // 避免出现内存耗尽的情况
    p = new Element;
  } catch(const std::bad_alloc& e ){
    return false;
  }

  p->data = data;
  p->next = top_;
  top_ = p;

  return true;
}  

template<class Type>
bool LinkStack<Type>::Pop(void) {
  if (IsEmpty())
    return false;
  Element *p = top_;
  top_ = top_->next;
  delete p;

  return true;
}

template<class Type>
const Type & LinkStack<Type>::Top(void) const {
  return top_->data;
}

template<class Type>
bool LinkStack<Type>::Top(Type & data) const {
  if (IsEmpty())
    return false;
  data = top_->data;
  return true;
}

template<class Type>
bool LinkStack<Type>::IsEmpty(void) const {
  return NULL == top_;
} 

template<class Type>
bool LinkStack<Type>::IsFull(void) const {
  Element *p = NULL;
  try {                 // 避免出现内存耗尽的情况
    p = new Element;
  } catch(const std::bad_alloc& e ){
    return true;
  }
  delete p;
  return false;
}
#endif // LINK_STACK
