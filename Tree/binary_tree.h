// C++ file
/*
 * 左右链结构的二叉树的遍历以及建立
 * */
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include<iostream>

template<class Type>
class BinaryTree{
  public:
    BinaryTree(void);
    BinaryTree(const BinaryTree & btree);
    ~BinaryTree(void);
    BinaryTree & operator=(const BinaryTree &btree);

    void MakeNULL(void);
    bool IsEmpty(void) const {return NULL = root_};
    void Create(void);

    void PreOrder(void) const;
    void InOrder(void) const;
    void PostOrder(void) const;

  private:
    struct BTreeNode{
      Type data;
      struct BTreeNode * lchild;
      struct BTreeNode * rchild;
    };
    BTreeNode * root_;
    
    void Visit(const BTreeNode * root) const;
   // recursive
    void RecurPreOrder(const BTreeNode * root) const;
    void RecurInOrder(const BTreeNode * root) const;
    void RecurPostOrder(const BTreeNode * root) const;
    void RecurCreate(const BTreeNode * &root);
   // Non-recursive
    void NonPRecurPreOrder() const;
    void NonRecurPInOrder() const;
    void NonPRecurPostOrder() const;
};

void BTreeNode::Visit(const BTreeNode * root) const
{/*{{{*/
  if (NULL != root)
    std::cout << root->data << endl;
  else
    std::cout << "NULL" << endl;
}/*}}}*/

// recursive
void BTreeNode::RecurPreOrder(const BTreeNode * root) const
{/*{{{*/
  if (NULL != root) {
    Visit(root);
    RecurPreOrder(root->lchild);
    RecurPreOrder(root->rchild);
  }
}/*}}}*/

void BTreeNode::RecurInOrder(const BTreeNode * root) const
{/*{{{*/
  if (NULL != root) {
    RecurInOrder(root->lchild);
    Visit(root);
    RecurInOrder(root->rchild);
  }
}/*}}}*/

void BTreeNode::RecurPostOrder(const BTreeNode * root) const
{/*{{{*/
  if(NULL != root) {
    RecurPostOrder(root->lchild);
    RecurPostOrder(root->rchild);
    Visit(root);
  }
}/*}}}*/

void BTreeNode::RecurCreate(const BTreeNode * &root)
{
  while(!(std::cin>>
  // #pass
}

// Non-recursive
void BTreeNode::NonPRecurPreOrder() const
{
  // #pass
}

void BTreeNode::NonRecurPInOrder() const
{
  // #pass
}

void BTreeNode::NonPRecurPostOrder() const
{
  // #pass
}

void BTreeNode::NonPRecurPostOrder() const
{
  // #pass
}

void BTreeNode::NonPRecurPostOrder() const
{
  // #pass
}

void BTreeNode::NonPRecurPostOrder() const
{
  // #pass
}

void BTreeNode::NonPRecurPostOrder() const
{
  // #pass
}

void BTreeNode::NonPRecurPostOrder() const
{
  // #pass
}


BTreeNode::BinaryTree(void)
{
  // #pass
}

BTreeNode::BinaryTree(const BinaryTree & btree)
{
  // #pass
}

BTreeNode::~BinaryTree(void)
{
  // #pass
}

BTreeNode::BinaryTree & operator=(const BinaryTree &btree)
{
  // #pass
}


void BTreeNode::MakeNULL(void)
{
  // #pass
}

bool BTreeNode::IsEmpty(void) const {return NULL = root_}
{
  // #pass
}

void BTreeNode::Create(void)
{
  // #pass
}

void BTreeNode::PreOrder(void) const
{
  // #pass
}

void BTreeNode::InOrder(void) const
{
  // #pass
}

void BTreeNode::PostOrder(void) const
{
  // #pass
}

#endif // BINARY_TREE_H
