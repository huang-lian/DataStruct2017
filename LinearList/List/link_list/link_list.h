#ifndef LINK_LIST_H
#define LINK_LIST_H

// 链式结构的线性表.
// 在本线性表中没有进行任何的参数合法性检查.
// 你在使用任何的postion 类型的参数,应当make sure the argment is Not NULL and 他来自本链表,
// 否则,后果是严重的.
// 检测链表是否为空,可以查看First 或者end的返回值是否为空.
// Append是一个无条件后插的方法.新增加的元素都在链表的结尾.
// 在first不为空的情况.可以使用Insert(First())实现头插法.
template<class Type>
class LinkList{
  public:
    struct Element {
      Type item;
      struct Element * next;
      Element(const Type & data) : item(data), next(NULL) {
      };
    };
    typedef Element * Postion;

    LinkList(void);
    LinkList(const LinkList<Type> & lk_l);
    ~LinkList(void);
    const LinkList<Type> & operator=(const LinkList<Type> & lk_l);

    void MakeNull(void);

    // 表添加一个数据
    bool Append(const Type & x);

    // 在pos后添加一个数据
    bool Insert(const Type & x,const Postion pos);

    // 删除地址为pos节点数据
    bool Delete(const Postion pos);

    // 返回第一个值与x相等的数据
    Postion Locate(const Type & x) const;

    // 返回数据位置
    const Type & Retrieve(const Postion pos) const;

    Postion Previous(const Postion pos) const;
    Postion Next(const Postion pos) const;

    Postion First(void) const;
    Postion End(void) const;

  private:

    Element * header_;
    Element * last_;
};

  template<class Type>
LinkList<Type>::LinkList(void) :header_(NULL),last_(NULL)
{/*{{{*/
}/*}}}*/

  template<class Type>
LinkList<Type>::LinkList(const LinkList<Type> & lk_l):header_(NULL),last_(NULL)
{/*{{{*/
  *this = lk_l;
}/*}}}*/

  template<class Type>
LinkList<Type>::~LinkList(void)
{/*{{{*/
  MakeNull();
}/*}}}*/

  template<class Type>
const LinkList<Type> & LinkList<Type>::operator=(const LinkList<Type> & lk_l)
{/*{{{*/
  if (&lk_l != this) {
    MakeNull();
    for(Postion p = lk_l.header_; NULL != p; p = p->next)
    {
      Append(p->item);
    }
  }
    return *this;
}/*}}}*/

  template<class Type>
void LinkList<Type>::MakeNull(void)
{/*{{{*/
  Element *p = header_;
  while(NULL != header_) {
    p = header_;
    header_= header_->next;
    delete p;
  }
}/*}}}*/

  template<class Type>
bool LinkList<Type>::Append(const Type & x)
{/*{{{*/
  if (NULL == header_) {
    header_ = new Element(x);
    last_ = header_;
  } else {
    last_->next = new Element(x);
    last_ = last_->next;
  }
  return true;
}/*}}}*/

// 插在pos位置,其余後移动
// 应确保pos存在链表中
  template<class Type>
bool LinkList<Type>::Insert(const Type & x, const Postion pos)
{/*{{{*/
  Postion p = new Element(pos->item);  // 新节点继承pos节点全部信息
  p->next = pos->next;
  pos->next = p;
  pos->item = x;              // x 赋值在pos
  if (pos == last_)
    last_ = p;
  return true;

}/*}}}*/

//  template<class Type>
//bool LinkList<Type>::Insert(const Type & x, const Postion pos)
//{/*{{{*/
//  for (Postion p = header_; NULL != p; p = p->next) {
//    if (pos == p) {
//      p = new Element(pos->item);  // 新节点继承pos节点全部信息
//      p->next = pos->next;
//      pos->next = p;
//      pos->item = x;              // x 插在pos
//      if (pos == last_)
//	last_ = p;
//      return true;
//    }
//  }
//  return false;
//}/*}}}*/

// 删除pos节点
// 返回删除结果
  template<class Type>
bool LinkList<Type>::Delete(const Postion pos)
{/*{{{*/
  if (NULL != pos) {
    Postion  p = header_;
    if (pos == header_) {  // 删除头的情况
      header_ = header_->next;
      if (pos == last_) last_ = header_;
      delete pos;
      return true;
    }
    for(p = header_; NULL != p; p = p->next) {
      if(pos == p->next) {
	p->next = pos->next;
	if (pos == last_) last_ = p;
	delete pos;
	return true;
      }
    }
  }
  return false;
}/*}}}*/

// 放回值为x的第一个节点,
// 不存在为null
template<class Type>
typename LinkList<Type>::Postion LinkList<Type>::Locate(const Type & x) const
{/*{{{*/
  Postion p = header_;
  for(; NULL != p; p = p->next) {
    if (x == p->data) {
      break;
    }
  }
  return p;
}/*}}}*/


// 返回pos位置的数据
// 应确保pos存在链表中
template<class Type>
const Type & LinkList<Type>::Retrieve(const Postion pos) const
{/*{{{*/
  return pos->item;
}/*}}}*/

// 返回前一个位置
// 应当确保pos存在
template<class Type>
typename LinkList<Type>::Postion LinkList<Type>::Previous(const Postion pos) const
{/*{{{*/
  Postion p = header_;
  Postion pr = NULL;
  for(;NULL != p; p = p->next) {
    if(pos == p) {
      return pr;
    }
    pr = p;
  }
  return NULL;
}/*}}}*/

// 返回下一个位置
// 应当确保pos存在
template<class Type>
typename LinkList<Type>::Postion LinkList<Type>::Next(const Postion pos) const
{/*{{{*/
  return pos->next;
}/*}}}*/

template<class Type>
typename LinkList<Type>::Postion LinkList<Type>::First(void) const
{/*{{{*/
  return header_;
}/*}}}*/

template<class Type>
typename LinkList<Type>::Postion LinkList<Type>::End(void) const
{/*{{{*/
  return last_;
}/*}}}*/

#endif //LINK_LIST_H
