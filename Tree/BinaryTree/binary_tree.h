// C++ file
/*
 * 左右链结构的二叉树的遍历以及建立
 * */
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include<iostream>
#include"link_stack.h"
#include"link_queue.h"
//template<class Type>
class BinaryTree{
  public:
    BinaryTree(void);
    BinaryTree(const BinaryTree & btree);
    ~BinaryTree(void);
    BinaryTree & operator=(const BinaryTree &btree);

    void MakeNull(void);
    bool IsEmpty(void) const {return NULL == root_;};
    void Create(void);

    void PreOrder(void) const;
    void InOrder(void) const;
    void PostOrder(void) const;
    void LeverOrder(void) const;
    size_t Count(void) const;
    size_t Height(void) const;
    void Exchange(void);

  private:
    struct BTreeNode{
 //     Type data;
      char data;
      struct BTreeNode * lchild;
      struct BTreeNode * rchild;
    };
    BTreeNode * root_;
    
    void Visit(const BTreeNode * root) const;
   // recursive
    void RecurPreOrder(const BTreeNode * root) const;
    void RecurInOrder(const BTreeNode * root) const;
    void RecurPostOrder(const BTreeNode * root) const;
    void RecurCreate(BTreeNode * &root);
   // Non-recursive
    void NonRecurPreOrder() const;
    void NonRecurInOrder() const;
    void NonRecurPostOrder() const;
    void NonRecurCreate();
    size_t Count(const BTreeNode * root) const;
    size_t Height(const BTreeNode * root) const;
    void Exchange(BTreeNode * & root);

    void Free(BTreeNode * &root);
};

using std::cout;
using std::endl;
using std::cin;
void BinaryTree::Visit(const BTreeNode * root) const
{/*{{{*/
  if (NULL != root)
    std::cout << root->data;
  else
    std::cout << "NULL" << std::endl;
}/*}}}*/

// recursive
void BinaryTree::RecurPreOrder(const BTreeNode * root) const
{/*{{{*/
  if (NULL != root) {
    Visit(root);
    RecurPreOrder(root->lchild);
    RecurPreOrder(root->rchild);
  }
}/*}}}*/

void BinaryTree::RecurInOrder(const BTreeNode * root) const
{/*{{{*/
  if (NULL != root) {
    RecurInOrder(root->lchild);
    Visit(root);
    RecurInOrder(root->rchild);
  }
}/*}}}*/

void BinaryTree::RecurPostOrder(const BTreeNode * root) const
{/*{{{*/
  if(NULL != root) {
    RecurPostOrder(root->lchild);
    RecurPostOrder(root->rchild);
    Visit(root);
  }
}/*}}}*/

void BinaryTree::RecurCreate(BTreeNode * &root)
{/*{{{*/
  char ch;
  std::cin >> ch;
  if( '#' == ch) {
    root = NULL;
  }
  else {
    root = new BTreeNode;
    root->data = ch;
    RecurCreate(root->lchild);
    RecurCreate(root->rchild);
  }
}/*}}}*/


// Non-recursive
void BinaryTree::NonRecurPreOrder() const
{/*{{{*/
  LinkStack<BTreeNode *> st;
  BTreeNode * p = root_;
  while(NULL != p || !st.IsEmpty()) {
    while(NULL != p) {
      st.Push(p);
      Visit(p);
      p = p->lchild;
    }
    if (st.Top(p)) {
      st.Pop();
      p = p->rchild;
    }
  }
  cout << endl;
}/*}}}*/

void BinaryTree::NonRecurInOrder() const
{/*{{{*/
  LinkStack<BTreeNode *> st;
  BTreeNode * p = root_;
  while(NULL != p || !st.IsEmpty()) {
    while(NULL != p) {
      st.Push(p);
      p = p->lchild;
    }
    if (st.Top(p)) {
      st.Pop();
      Visit(p);
      p = p->rchild;
    }
  }
  cout << endl;
}/*}}}*/

void BinaryTree::NonRecurPostOrder() const
{/*{{{*/
  struct PostOrderView{
    BTreeNode * ptr;
    int tag;  // 1 表示初次访问
    		// 2 表示第二次访问
  };
  LinkStack<struct PostOrderView*> st;
  struct PostOrderView *ptmp = NULL;
  BTreeNode * p = root_;
  while(NULL != p || !st.IsEmpty()) {
    for(;NULL != p; p = p->lchild) {
      // 将初次访问到的元素存入.一直到左叶子节点
      ptmp = new PostOrderView;
      ptmp->ptr = p;
      ptmp->tag = 1;
      st.Push(ptmp);
    }
    while(st.Top(ptmp)&& 2 == ptmp->tag){
      Visit(ptmp->ptr);
      st.Pop();
    }
    if(st.Top(ptmp)) {
      ptmp->tag = 2;  //  
      st.Pop();
      st.Push(ptmp);
      p = ptmp->ptr;
      p = p->rchild; // 遍历右
    }
  }
  cout << endl;
}/*}}}*/

void BinaryTree::NonRecurCreate()
{/*{{{*/
  int i=0, j = 0;
  char ch = '#';
  struct BTreeNode *p;
  const int max_size = 101;
  struct BTreeNode *arr[max_size];   // 用于保存结点地址,便于后续录入.
  cout << "\
    非递归建立左右链式的二叉树.\n\
    依次输入结点编号 节点数据.以空白符号分隔.\n\
    结束标识是: 0 # \n\
    示例:\n\
    1 A 2 B 3 C 4 D 5 E 6 F 7 G 8 H 9 I 11 J 0 #\n\
    说明:\n\
    1. 最大元素数量默认为100,暂时不提供修改.\n\
    2. 节点编号按照层序编号,其中中空节点也需要编号\n\
    3. 编号顺序从1开始.即根节点(root)编号为1.编号范围[1,100].\n\
    3. 存在相同编号,则数据保存的是最后输入的节点.而且这会造成内存泄漏.\n\
    4. 不符合二叉树结构的数据也会造成内存泄漏或者错误.暂时未解决.\n\
    参考: DS2017_PPT-3-45_Li\n\
    逻辑上是和完全二叉树的顺序存储结构一致";
  cin >> i >> ch;
  if(!cin.good()) {
    cout << "输入有错误!\n";
    cin.clear();
    while('\n' != cin.get());
  }
  while(i>0 && i < max_size&& '#' != ch)
  {
    p = new BTreeNode;
    p->data = ch;
    p->lchild = p->rchild= NULL;
    arr[i] = p;  // 保存数据
    if(1 == i) {
      root_ = p;
    } else {
      j = i/2;
      if( 0 == i%2) {
	arr[j]->lchild = p;
      } else {
	arr[j]->rchild = p;
      }
    }
    cin >>i >> ch;
    if(!cin.good()) {
      cout << "输入有错误!\n";
      cin.clear();
      while('\n' != cin.get());
      break;
    }
  }
}/*}}}*/

size_t BinaryTree::Count(const BTreeNode * root) const
{/*{{{*/
  if (NULL == root)
    return 0;
  return Count(root->lchild) + Count(root->rchild) + 1;
}/*}}}*/

void BinaryTree::Exchange(BTreeNode * &root)
{/*{{{*/
  if(NULL != root) {
  BTreeNode *p = root->lchild;
  root->lchild = root->rchild;
  root->rchild = p;
  Exchange(root->lchild);
  Exchange(root->rchild);
  }
}/*}}}*/


size_t BinaryTree::Height(const BTreeNode * root) const 
{/*{{{*/
  if (NULL == root)
    return 0;
  size_t n = Height(root->lchild);
  size_t m = Height(root->rchild);
  return (m>n)?m + 1: n +1;
}/*}}}*/
void BinaryTree::Free(BTreeNode * & root)
{/*{{{*/
  if(NULL != root)
  {
    Free(root->lchild);
    Free(root->rchild);
    delete root;
    root = NULL;
  }

}/*}}}*/

BinaryTree::BinaryTree(void)
{/*{{{*/
  root_ = NULL;
}/*}}}*/

BinaryTree::BinaryTree(const BinaryTree & btree)
{/*{{{*/
  // #pass
}/*}}}*/

BinaryTree::~BinaryTree(void)
{/*{{{*/
  Free(root_);
}/*}}}*/

BinaryTree & BinaryTree::operator=(const BinaryTree &btree)
{
  if (&btree == this)
    return *this;

  MakeNull();
  // #pass
  return *this;

}

void BinaryTree::MakeNull(void)
{/*{{{*/
  Free(root_);
}/*}}}*/

void BinaryTree::Create(void)
{/*{{{*/
  cout << "\
    按照先序序列建立左右链式结构的二叉树\n\
    ,每个字符代表一个节点数据,以#表示空.\n\
    示例:\n\
    ABDH##I##E##CF##J##G##\n";
  RecurCreate(root_);
  NonRecurCreate();
  // #fix
  //
}/*}}}*/

void BinaryTree::PreOrder(void) const
{/*{{{*/
  cout << "递归先序遍历\n";
  RecurPreOrder(root_);
  cout << endl;
  cout << "非递归先序遍历\n";
  NonRecurPreOrder();
}/*}}}*/

void BinaryTree::InOrder(void) const
{/*{{{*/
  cout << "递归中序遍历\n";
  RecurInOrder(root_);
  cout << endl;
  cout << "非递归中序遍历\n";
  NonRecurInOrder();
}/*}}}*/

void BinaryTree::PostOrder(void) const
{/*{{{*/
  cout << "递归后序遍历\n";
  RecurPostOrder(root_);
  cout << endl;
  cout << "非递归后续遍历\n";
  NonRecurPostOrder();
} /*}}}*/

void BinaryTree::LeverOrder(void) const
{/*{{{*/
  cout << "层序遍历\n";
  LinkQueue<BTreeNode *> que;
  BTreeNode *p = root_;
  if (NULL == root_) {
    Visit(p);
    return;
  }
  que.EnQueue(p);
  while(!que.IsEmpty()) {
    que.Front(p);
    que.DeQueue(); 
    Visit(p);
    if(NULL != p->lchild) {
      que.EnQueue(p->lchild);
    }

    if(NULL != p->rchild) {
      que.EnQueue(p->rchild);
    }
  }
  cout << endl;
}/*}}}*/

size_t BinaryTree::Count(void) const
{/*{{{*/
  size_t num = Count(root_);
  cout << "num = " << num << endl;
  return num;
}/*}}}*/

size_t BinaryTree::Height(void) const
{/*{{{*/
  size_t h = Height(root_);
  cout << "Height = " << h << endl;
  return h;
}/*}}}*/

void BinaryTree::Exchange(void)
{
  cout << "交换前";
  LeverOrder();
  Exchange(root_);
  cout << "交换后";
  LeverOrder();
}
#endif // BINARY_TREE_H
