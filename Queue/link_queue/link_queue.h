// C++ file
/* 链式结构队列
 * Author:huang_lian@126.com
 * date:2017年10月21日 星期六
 **/
#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H
template<class Type>
class LinkQueue{
  public:
    LinkQueue(void);
    LinkQueue(const LinkQueue<Type> & lk_q);
    ~LinkQueue(void);

    const LinkQueue<Type> & operator=(const LinkQueue<Type> & lk_q);
    
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
    struct Element{
      Type data;
      struct Element * next;
    };

    Element * front_;
    Element * rear_;

};

template<class Type>
LinkQueue<Type>::LinkQueue(void) {
  front_ = NULL;
  rear_ = NULL;
}
template<class Type>
LinkQueue<Type>::LinkQueue(const LinkQueue<Type> & lk_q) {
  Element *p = lk_q.front_; // 按照之前的序列入队
  Element * new_elem = NULL;

  // 单独处理第一节点,避免以后每次都要判断
  if (NULL != p) {
    rear_ = new Element;
    rear_->data = p->data;
    p = p->next;
  }
  while(NULL != p) {
    new_elem = new Element;
    new_elem->data = p->data;

    rear_->next = new_elem;
    p = p->next;
  }
  rear_->next = NULL;
}

template<class Type>
LinkQueue<Type>::~LinkQueue(void) {
  MakeNull();
}

template<class Type>
const LinkQueue<Type> & LinkQueue<Type>::operator=(const LinkQueue<Type> & lk_q) {
  if (&lk_q == this)
    return *this;
  MakeNull();

  Element *p = lk_q.front_; // 按照之前的序列入队
  Element * new_elem = NULL;

  // 单独处理第一节点,避免以后每次都要判断
  if (NULL != p) {
    rear_ = new Element;
    rear_->data = p->data;
    front_ = rear_;
    p = p->next;
  }
  while(NULL != p) {
    new_elem = new Element;
    new_elem->data = p->data;

    rear_->next = new_elem;
    p = p->next;
  }
  rear_->next = NULL;
}

template<class Type>
void LinkQueue<Type>::MakeNull(void) {
  Element *p = NULL;
  while(NULL != front_) {
    p = front_;
    front_ = front_->next;
    delete p;
  }
  rear_ = NULL;
}
template<class Type>
bool LinkQueue<Type>::EnQueue(const Type & data) {
  Element *new_elem = NULL;

  try {
  new_elem = new Element;
  } catch(const std::bad_alloc& e) {
    return false;
  }
  new_elem->data = data;
  new_elem->next = NULL;
  if(NULL == rear_) {
    rear_ = new_elem;
    front_ = new_elem;
  } else {
    rear_->next = new_elem;
    rear_ = new_elem;
  }
  return true;
}

template<class Type>
bool LinkQueue<Type>::DeQueue(void) {
  if (IsEmpty())
    return false;

  if (rear_ == front_) // 仅有一个节点时
    rear_ = NULL;
  Element *p = front_;
  front_ = front_->next;
  delete p;
  
  return true;
}

template<class Type>
const Type & LinkQueue<Type>::Front(void) const {
  if (!IsEmpty())
    return front_->data;
  Type zero;  // 避免出现段错误返回一个默认值
  return zero;
}

template<class Type>
bool LinkQueue<Type>::Front(Type & data) const  {
  if (IsEmpty())
    return false;
  data = front_->data;
  return true;
}

template<class Type>
bool LinkQueue<Type>::IsEmpty(void) const {
  if (NULL == front_)
    return true;
  return false;
}

template<class Type>
bool LinkQueue<Type>::IsFull(void) const {
  Element * new_elem = NULL;
  try {
    new_elem = new Element;
  } catch(const std::bad_alloc& e) {
    return true;
  }
  delete new_elem;
  return false;
}
#endif // LINK_QUEUE_H
