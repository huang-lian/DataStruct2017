// C++ file
/* 多个栈共享空间 
 * author：huang_lian@126.com
 **/
#ifndef LINK_STACK
#define LINK_STACK
#define MAX_LENGTH 100
template<class Type>
class ShareStack{
  public:
    explicit ShareStack(void);
    ~ShareStack(void);

    // 第一次使用的时候应当调用本函数
    // 谨慎使用，这会清空整个空间数据

    void MakeNull(void); 
    // 本函数和析构函数相关，放置在此

    bool Push(const Type & data);
    bool Pop(void);

    const Type & Top(void) const;
    // 应该检查是否为空后再使用

    bool Top(Type & data) const;

    bool IsEmpty(void) const;
    bool IsFull(void) const;

    void ShowStack(void) const;

  private: 
    struct Element{
      Type data;
      size_t next;
    };
    
    void InitSpace(void);
    size_t NewNode(void);
    void FreeNode(size_t & n);

    static bool flag_;   // 标记是否是第一次使用，初始化空间
    static size_t cursor_; // av  始终指向将要被分配的节点
    static  Element space_[MAX_LENGTH];
    size_t top_;    //始终指向栈顶元素,当 
};
template<class Type>
bool ShareStack<Type>::flag_ = true;

template<class Type>
size_t ShareStack<Type>::cursor_ = 0;

template<class Type>
struct ShareStack<Type>::Element ShareStack<Type>::space_[MAX_LENGTH] = {};

template<class Type>
void ShareStack<Type>::InitSpace(void) {
  if (!flag_) return;
  flag_ = false;
  for(size_t i = 0; i < MAX_LENGTH; i++) {
    space_[i].next = i + 1;
  }
}
template<class Type>
size_t ShareStack<Type>::NewNode(void) {
  if (MAX_LENGTH == cursor_)
    return cursor_;
  size_t p = cursor_;
  cursor_ = space_[cursor_].next;
  return p;
}

template<class Type>
void ShareStack<Type>::FreeNode(size_t & n) {
  if (MAX_LENGTH <= n) return;
  space_[n].next = cursor_;
  cursor_ = n;
  n = MAX_LENGTH;
}
template<class Type>
ShareStack<Type>::ShareStack(void) :top_(MAX_LENGTH) {
  InitSpace();
}

template<class Type>
ShareStack<Type>::~ShareStack(void) {
  MakeNull();
}

template<class Type>
void ShareStack<Type>::MakeNull(void) {
  size_t p = top_;
  while(!IsEmpty()) {
    p = top_;
    top_ = space_[top_].next;
    FreeNode(p);
  }
}

template<class Type>
bool ShareStack<Type>::Push(const Type & data) {
  if (IsFull())
    return false;

  size_t p = MAX_LENGTH;
  p = NewNode();

  space_[p].data = data;
  space_[p].next = top_;
  top_ = p;

  return true;
}  

template<class Type>
bool ShareStack<Type>::Pop(void) {
  if (IsEmpty())
    return false;

  size_t p = top_;
  top_ = space_[top_].next;
  FreeNode(p);

  return true;
}

template<class Type>
const Type & ShareStack<Type>::Top(void) const {
  return space_[top_].data;
}

template<class Type>
bool ShareStack<Type>::Top(Type & data) const {
  if (IsEmpty())
    return false;
  data = space_[top_].data;
  return true;
}

template<class Type>
bool ShareStack<Type>::IsEmpty(void) const {
  return MAX_LENGTH == top_;
} 

template<class Type>
bool ShareStack<Type>::IsFull(void) const {
  return MAX_LENGTH == cursor_;
}

template<class Type>
void ShareStack<Type>::ShowStack(void) const {
  int p = top_;
  using std::cout;
  using std::endl;
  cout << "Now cursor at " << cursor_ << endl;
  cout << "max size is " << MAX_LENGTH << endl;
  cout <<"##TOP\n";
  cout <<"index\tnext\tdata\n";
  while(MAX_LENGTH != p) {
    cout <<"||" << p << "\t"
	      << space_[p].next << "\t"<< space_[p].data << endl;
    p = space_[p].next;
  }
  cout << "BOTTON###\n";
}
#endif // LINK_STACK
