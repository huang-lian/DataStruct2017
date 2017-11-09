// C++ file
/* 中序线索二叉树
 *
 * */
#ifndef THREADED_BINARY_TREE_H
#define THREADED_BINARY_TREE_H
template<class Type>
class  ThreadedBTree{
  ThreadedBTree(void);
  ThreadedBTree(const ThreadedBTree & tbt);
  ~ThreadedBTree(void);

    BinaryTree & operator=(const BinaryTree &btree);

    void MakeNull(void);
    bool IsEmpty(void) const {return NULL == root_;};
    void Create(void);

    void PreOrder(void) const;
    void InOrder(void) const;
    void PostOrder(void) const;
    void LeverOrder(void) const;

  private:
    struct TBTNode{
      Type data;
      bool ltag;
      bool rtag;
      struct TBTNode * lchild;
      struct TBTNode * rchild;
    };
    TBTNode * root_;
    
    void Free(TBTNode * &root);
    TBTNode * Copy(const TBTNode * root);
};

#endif // THREADED_BINARY_TREE_H
