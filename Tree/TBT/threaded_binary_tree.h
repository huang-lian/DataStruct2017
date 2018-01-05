
// C++ file
/* 状态：啥都没写完
 * 左右链结构的线索二叉树的模板
 * */
#ifndef THREADED_BINARY_TREE_H
#define THREADED_BINARY_TREE_H
#include<iostream>
template<class Type>
class ThreadedBT{
  public:
    ThreadedBT(void);
    ThreadedBT(const ThreadedBT & tbt);
    ~ThreadedBT(void);
    ThreadedBT & operator=(const ThreadedBT &tbt);

    void MakeNull(void);
    bool IsEmpty(void) const {return NULL == root_;};
    void Create(void);

    void PreOrder(void) const;
    void InOrder(void) const;
    void PostOrder(void) const;
    void LeverOrder(void) const;
    void LeverNumAndRight(void) const;
    size_t Count(void) const;
    size_t Height(void) const;
    void Exchange(void);
    bool operator==(const ThreadedBT & tbt);
  private:
    struct TBTNode{
      Type data;
      bool ltag;
      bool rtag;
      struct TBTNode * lchild;
      struct TBTNode * rchild;
    };
    TBTNode * root_;
    TBTNode * InNext(const TBTNode * pre);
    TBTNode * PreNext(const TBTNode * pre);
    TBTNode * PostNext(const TBTNode * pre);
    void RInsert(const TBTNode *Dest, const TBTNode *NewRNode);
    void InOrderTh(TBTNode * root);

    void Visit(const TBTNode * root) const;
    size_t Count(const TBTNode * root) const;
    size_t Height(const TBTNode * root) const;
    bool Equal(const TBTNode * root1, const TBTNode *root2);
    TBTNode * Copy(const TBTNode * root);

    void Free(TBTNode * &root);
};

template<class Type>
void ThreadedBT<Type>::Visit(const TBTNode * root) const
{
  // #pass
}

template<class Type>
size_t ThreadedBT<Type>::Count(const TBTNode * root) const 
{
  // #pass
}

template<class Type>
size_t ThreadedBT<Type>::Height(const TBTNode * root) const 
{
  // #pass
}

  template<class Type>
bool ThreadedBT<Type>::Equal(const TBTNode * root1, const TBTNode *root2)
{
  // #pass
}

  template<class Type>
typename ThreadedBT<Type>::TBTNode * ThreadedBT<Type>::Copy(const TBTNode * root)
{
  // #pass
}

  template<class Type>
void ThreadedBT<Type>::Free(TBTNode * & root)
{
  // #pass
}

  template<class Type>
ThreadedBT<Type>::ThreadedBT(void)
{
  // #pass
}

  template<class Type>
ThreadedBT<Type>::ThreadedBT(const ThreadedBT & btree)
{
  // #pass
}

  template<class Type>
ThreadedBT<Type>::~ThreadedBT(void)
{
  // #pass
}

  template<class Type>
ThreadedBT<Type> & ThreadedBT<Type>::operator=(const ThreadedBT<Type> &btree)
{
  // #pass
}

  template<class Type>
void ThreadedBT<Type>::MakeNull(void)
{
  // #pass
}

  template<class Type>
void ThreadedBT<Type>::Create(void)
{
  // #pass
}

template<class Type>
void ThreadedBT<Type>::PreOrder(void) const
{
  // #pass
}

template<class Type>
void ThreadedBT<Type>::InOrder(void) const
{
  // #pass
}

template<class Type>
void ThreadedBT<Type>::PostOrder(void) const
{
  // #pass
}

template<class Type>
void ThreadedBT<Type>::LeverOrder(void) const
{
  // #pass
}

template<class Type>
void ThreadedBT<Type>::LeverNumAndRight(void) const
{
  // #pass
}

template<class Type>
size_t ThreadedBT<Type>::Count(void) const
{
  // #pass
}

template<class Type>
size_t ThreadedBT<Type>::Height(void) const
{
  // #pass
}

  template<class Type>
void ThreadedBT<Type>::Exchange(void)
{
  // #pass
}
  template<class Type>
bool ThreadedBT<Type>::operator==(const ThreadedBT<Type> & bt)
{
  return Equal(root_, bt.root_);
}
#endif // THREADED_BINARY_TREE_H
