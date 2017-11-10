#ifndef LINK_LIST_H
#define LINK_LIST_H
template<class Type>
class LinkList{
  public:
    LinkList(void);
    LinkList(const LinkList<Type> & lk_l);
    ~LinkList(void);
    const LinkList<Type> & operator=(const LinkList<Type> & lk_l);

    void MakeNull(void);

    bool Append(const Type & x);
    bool Insert(const Type & x, size_t pos);
    bool Delete(size_t pos);

    size_t Locate(const Type & x) const;
    const Type & Retrieve(size_t pos) const;

    const Type & Previous(size_t pos) const;
    const Type & Next(size_t pos) const;
    const Type & First(void) const;
    const Type & End(void) const;

    size_t size(void) const {return size_;};
    const Type & operator[](size_t pos) const;
    Type & operator[](size_t pos); 
  private:
    // 合并operator=和拷贝构造函数公共内容
    void SetLink(const LinkList<Type> & lk_l);

    // 使用头插法,使得建立表更加容易
    // 新建立的节点对应的索引值更大,总是指向前一个节点
    struct Element {
      Type data;
      struct Element * previous;
    };
    size_t size_;
    Element * header;
};

template<class Type>
void LinkList<Type>::SetLink(const LinkList<Type> & lk_l) {
  size_ = lk_l.size_;

  Element *p = lk_l.header;
  Element *new_elemt = NULL;
  Element *pre_elemt = NULL;

  if(NULL != p) {
    new_elemt = new Element;
    new_elemt->data = p->data;
    header = new_elemt;
    pre_elemt = new_elemt;

    p = p->previous;
  }
  while(NULL != p) {
    new_elemt = new Element;
    new_elemt->data = p->data;
    pre_elemt->previous = new_elemt;
    pre_elemt = new_elemt;

    p = p->previous;
  }
  pre_elemt->previous = NULL;
}
template<class Type>
LinkList<Type>::LinkList(void) : size_(0), header(NULL) {
}

template<class Type>
LinkList<Type>::LinkList(const LinkList<Type> & lk_l) {
  SetLink(lk_l);
}

template<class Type>
LinkList<Type>::~LinkList(void) {
  MakeNull();
}
template<class Type>
const LinkList<Type> & LinkList<Type>::operator=(const LinkList<Type> & lk_l) {
  if (&lk_l == this)
    return *this;
  MakeNull();
  SetLink(lk_l);
}
template<class Type>
void LinkList<Type>::MakeNull(void) {
  size_ = 0;

  Element *p = header;
  while(NULL != header) {
    p = header;
    header = header->previous;
    delete p;
  }
}

// 追加快速,头插法:
template<class Type>
bool LinkList<Type>::Append(const Type & x) {
  Element * new_elemt = NULL;
  try {
    new_elemt = new Element;
  } catch (const std::bad_alloc & e) {
    return false;
  }
  size_ ++;
  new_elemt->data = x;
  new_elemt->previous = header;
  header = new_elemt;

  return true;
}

template<class Type>
bool LinkList<Type>::Insert(const Type & x, size_t pos) {
  if (pos > size_) return false;
  if (pos == size_) return Append(x);

  Element * new_elemt = NULL;
  try {
    new_elemt= new Element;
  } catch (const std::bad_alloc & e) {
    return false;
  }
  new_elemt->data = x;

  Element *p = NULL;  // p标识要插入的节点的前一个节点,对应的索引值大1
  p = header;

  // 考虑pos==size_ -2 是不进入循环
  // #fixed
  for(size_t i = size_ - 2; i > pos;i--) {
    p = p->previous;
  }

  new_elemt->previous = p->previous;  // 继承pre
  p->previous = new_elemt;   // p->pre 是新的元素

  size_++;
  return true;
}

template<class Type>
bool LinkList<Type>::Delete(size_t pos) {
  if (pos > size_ -1) return false;
  Element * p = NULL;  // 标识待删除节点
  if (pos == size_ -1) {
    p = header;
    header = header->previous;
  } else {
    Element *pre = header;  // 标识要删除的节点的前一个节点,对应的索引值大1

    // 假定要删除的是索引pos为size_ - 2的值
    // 需要pre索引为size-1,不发生计数,直接操作
    for(size_t i = size_ - 2; i > pos;i--) { 
      pre = pre->previous;
    }
    p = pre->previous;
    pre->previous = p->previous;
  }

  size_ --;
  delete p;
  return true;
}

template<class Type>
size_t LinkList<Type>::Locate(const Type & x) const {
  Element *p = header;
  for(size_t i = (size_ -1); NULL != p;i--) {
    if (x == p.data)
      return i;
    p = p->previous;
  }
  return -1;
}

template<class Type>
const Type & LinkList<Type>::Retrieve(size_t pos) const {
  return (*this)[pos];
}

template<class Type>
const Type & LinkList<Type>::Previous(size_t pos) const {
  return (*this)[pos-1];
}

template<class Type>
const Type & LinkList<Type>::Next(size_t pos) const {
  return (*this)[pos+1];
}

template<class Type>
const Type & LinkList<Type>::First(void) const {
  return (*this)[0];
}

template<class Type>
const Type & LinkList<Type>::End(void) const {
  return (*this)[size_ -1];
}

// pos 越界必然段错误
template<class Type>
const Type & LinkList<Type>::operator[](size_t pos) const {
  Element *p = header;
  for(size_t i = size_ -1; i > pos; i--){
    p = p->previous;
  }
  return p->data;
}

template<class Type>
Type & LinkList<Type>::operator[](size_t pos) {
  Element *p = header;
  for(size_t i = size_ -1; i > pos; i--) {
    p = p->previous;
  }
  return p->data;
}
#endif //LINK_LIST_H
