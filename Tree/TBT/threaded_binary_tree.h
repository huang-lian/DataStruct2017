
// C++ file
/* 状态：啥都没写完
 * 左右链结构的线索二叉树的模板
 * */
#ifndef THREADED_BINARY_TREE_H
#define THREADED_BINARY_TREE_H
#include<iostream>
#include"link_stack.h"
#include"link_queue.h"
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
    void Exchange(TBTNode * & root);
    bool Equal(const TBTNode * root1, const TBTNode *root2);
    TBTNode * Copy(const TBTNode * root);

    void Free(TBTNode * &root);
};

template<class Type>
void ThreadedBT<Type>::Visit(const TBTNode * root) const
{/*{{{*/
  if (NULL != root)
    std::cout << root->data;
  else
    std::cout << "NULL" << std::endl;
}/*}}}*/

template<class Type>
size_t ThreadedBT<Type>::Count(const TBTNode * root) const 
{/*{{{*/ 
  if (NULL == root) 
    return 0;
  return Count(root->lchild) + Count(root->rchild) + 1;
}/*}}}*/

template<class Type>
void ThreadedBT<Type>::Exchange(TBTNode * &root)
{/*{{{*/
  if (NULL != root)
  { 
    TBTNode *p = root->lchild;
    root->lchild = root->rchild;
    root->rchild = p;
    Exchange(root->lchild);
    Exchange(root->rchild);
  }
}/*}}}*/


template<class Type>
size_t ThreadedBT<Type>::Height(const TBTNode * root) const 
{/*{{{*/
  if (NULL == root)
    return 0;
  size_t n = Height(root->lchild);
  size_t m = Height(root->rchild);
  return (m>n)?m + 1: n +1;
}/*}}}*/

  template<class Type>
bool ThreadedBT<Type>::Equal(const TBTNode * root1, const TBTNode *root2)
{/*{{{*/
  if (NULL == root1 && NULL == root2)
    return true;
  if (NULL != root1 && NULL != root2)
    if (root1->data == root2->data)
      return Equal(root1->lchild,root2->rchild);
  return false;
} //:~Equal/*}}}*/

  template<class Type>
typename ThreadedBT<Type>::TBTNode * ThreadedBT<Type>::Copy(const TBTNode * root)
{/*{{{*/
  TBTNode * tmp = NULL;
  if(NULL != root) {
    tmp = new TBTNode;
    tmp->data = root->data;
    tmp->lchild = Copy(root->lchild);
    tmp->rchild = Copy(root->rchild);
  }
  return tmp;
} //:~Copy/*}}}*/

  template<class Type>
void ThreadedBT<Type>::Free(TBTNode * & root)
{/*{{{*/
  if(NULL != root)
  {
    Free(root->lchild);
    Free(root->rchild);
    delete root;
    root = NULL;
  }

}/*}}}*/

  template<class Type>
ThreadedBT<Type>::ThreadedBT(void)
{/*{{{*/
  root_ = NULL;
}/*}}}*/

  template<class Type>
ThreadedBT<Type>::ThreadedBT(const ThreadedBT & btree)
{/*{{{*/
  root_ = Copy(btree.root_);
}/*}}}*/

  template<class Type>
ThreadedBT<Type>::~ThreadedBT(void)
{/*{{{*/
  Free(root_);
}/*}}}*/

  template<class Type>
ThreadedBT<Type> & ThreadedBT<Type>::operator=(const ThreadedBT<Type> &btree)
{/*{{{*/
  if (&btree == this)
    return *this;

  MakeNull();
  root_ = Copy(btree.root_);
  return *this;

}/*}}}*/

  template<class Type>
void ThreadedBT<Type>::MakeNull(void)
{/*{{{*/
  Free(root_);
}/*}}}*/

  template<class Type>
void ThreadedBT<Type>::Create(void)
{/*{{{*/
  int i=0, j = 0;
  Type data;
  struct TBTNode *p;
  const int max_size = 101;
  struct TBTNode *arr[max_size];   // 用于保存结点地址,便于后续录入.
  std::cout << "\
    非递归建立左右链式的二叉树.\n\
    依次输入结点编号 节点数据.以空白符号分隔.\n\
    结束标识节点是编号小于１: \n\
    示例:\n\
    1 A 2 B 3 C 4 D 5 E 6 F 7 G 8 H 9 I 11 J 0 #\n\
    说明:\n\
    1. 最大元素数量默认为100,暂时不提供修改.\n\
    2. 节点编号按照层序编号,其中中空节点也需要编号\n\
    3. 编号顺序从1开始.即根节点(root)编号为1.编号范围[1,100].\n\
    3. 存在相同编号,则数据保存的是最后输入的节点.而且这会造成内存泄漏.\n\
    4. 不符合二叉树结构的数据也会造成内存泄漏或者错误.暂时未解决.\n\
    参考: DS2017_PPT-3-45_Li\n\
    逻辑上是和完全二叉树的顺序存储结构一致\n";
  while(true) {
    std::cin >> i;

    if(!std::cin.good()) {
      std::cout << "输入有错误!\n";
      std::cin.clear();
      while('\n' != std::cin.get());
      break;
    }

    if(1 > i)
      break;
    std::cin >> data;
    if(!std::cin.good()) {
      std::cout << "输入有错误!\n";
      std::cin.clear();
      while('\n' != std::cin.get());
      break;
    }

    p = new TBTNode;
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
  }
}/*}}}*/

template<class Type>
void ThreadedBT<Type>::PreOrder(void) const
{/*{{{*/
  std::cout << "非递归先序遍历\n";
  LinkStack<TBTNode *> st;
  TBTNode * p = root_;
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
  std::cout << std::endl;
}/*}}}*/

template<class Type>
void ThreadedBT<Type>::InOrder(void) const
{/*{{{*/
  std::cout << "非递归中序遍历\n";
  LinkStack<TBTNode *> st;
  TBTNode * p = root_;
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
  std::cout << std::endl;
}/*}}}*/

template<class Type>
void ThreadedBT<Type>::PostOrder(void) const
{/*{{{*/
  std::cout << "非递归后序遍历\n";
  struct PostOrderView{
    TBTNode * ptr;
    int tag;  // 1 表示初次访问
    // 2 表示第二次访问
  };
  LinkStack<struct PostOrderView*> st;
  struct PostOrderView *ptmp = NULL;
  TBTNode * p = root_;
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
  std::cout << std::endl;
}/*}}}*/

template<class Type>
void ThreadedBT<Type>::LeverOrder(void) const
{/*{{{*/
  std::cout << "层序遍历\n";
  LinkQueue<TBTNode *> que;
  TBTNode *p = root_;
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
  std::cout << std::endl;
}/*}}}*/

template<class Type>
void ThreadedBT<Type>::LeverNumAndRight(void) const
{/*{{{*/
  std::cout << "每一层最后一个元素\n";
  LinkQueue<TBTNode *> que;
  TBTNode *p = root_;
  TBTNode *pre = root_;
  size_t lever = 0;
  size_t count = 0;
  if (NULL == root_) {
    Visit(p);
    return;
  }
  que.EnQueue(p);
  que.EnQueue(NULL);
  while(!que.IsEmpty()) {
    pre = p; //每一行的开头了?
    que.Front(p);
    que.DeQueue(); 
    if (NULL == p) {
      lever ++;
      std::cout << "Lever " << lever << "\tNo." << count <<"\t";
      Visit(pre);
      std::cout << std::endl;
      count = 0;
      if (que.IsEmpty())
	break;
      que.EnQueue(p);
    } else {
      count++;
      if (NULL != p->lchild) {
	que.EnQueue(p->lchild);
      }
      if (NULL != p->rchild) {
	que.EnQueue(p->rchild);
      }
    }
  }
  std::cout << std::endl;
}/*}}}*/

template<class Type>
size_t ThreadedBT<Type>::Count(void) const
{/*{{{*/
  size_t num = Count(root_);
  std::cout << "num = " << num << std::endl;
  return num;
}/*}}}*/

template<class Type>
size_t ThreadedBT<Type>::Height(void) const
{/*{{{*/
  size_t h = Height(root_);
  std::cout << "Height = " << h << std::endl;
  return h;
}/*}}}*/

  template<class Type>
void ThreadedBT<Type>::Exchange(void)
{/*{{{*/
  std::cout << "交换前";
  LeverOrder();
  Exchange(root_);
  std::cout << "交换后";
  LeverOrder();
}/*}}}*/

  template<class Type>
bool ThreadedBT<Type>::operator==(const ThreadedBT<Type> & bt)
{
  return Equal(root_, bt.root_);
}
#endif // THREADED_BINARY_TREE_H
