#include"poly.h"

bool Poly::Insert(int coef , int exp) {
  PolyNode *  newnode = new PolyNode;
  newnode->coef = coef;
  newnode->exp = exp;
  newnode->next = NULL;
  // 如果是空表达式,或者幂次大于第一项
  // 新的节点需要作为头节点
  if (NULL == header || header->exp < newnode->exp) {
    newnode->next = header;
    header = newnode;
    return true;
  }
  // 查找最后一个幂次大于或者等于newnode的节点
  PolyNode *pre = NULL;
  PolyNode *p = header;
  for(;NULL != p && newnode->exp < p->exp; p = p->next) {
    pre = p;
  }
  // 完成查找,p或者为NULL p->exp <= newnode->exp
  // pre 是前一个节点
  
  // p没有前节点,说明新节点的幂次和头节点幂次相等.
  if (NULL == pre) {
    header->coef += newnode->coef;
    delete newnode;
    if (0 == header->coef) {
      header = p->next;
      delete p;
    }
    return false;
  }

  // 新插入的节点幂次最小.直接接在最后
  if (NULL == p) {
    pre->next = newnode;
    return true;
  }

  // 存在一个相等的节点,且这个节点不为头节点
  if (p->exp == newnode->exp) {
    p->coef += newnode->coef;
    delete newnode;
    if (0 == p->coef) {
      pre->next = p->next;
      delete p;
    }
    return false;
  }

  // pre是最后一个幂次大于newnode的幂次的节点.
  newnode->next = pre->next;
  pre->next = newnode;
  return true;
}

void Poly::Free(void) {
  PolyNode * p = header;
  while(NULL != header) {
    p = header;
    header = header->next;
    delete p;
  }
  header = NULL;
}

Poly::Poly(void) {
  header = NULL;
}
Poly::Poly(int m, int n) {
  header = new PolyNode;
  header->coef = m;
  header->exp = n;
  header->next = NULL;
}

Poly::Poly(const Poly & apoly) {
  header = NULL;
  *this = apoly;
}

Poly::~Poly(void) {
  Free();
}

const Poly & Poly::operator=(const Poly & apoly) {
  if (&apoly == this)
    return *this;
  Free();

  PolyNode * p = apoly.header;
  while(NULL != p) {
    Insert(p->coef,p->exp);
  }
  return *this;
}

const Poly & Poly::operator+=(const Poly & apoly)
{
  for(PolyNode * p = apoly.header; NULL != p;p = p->next) {
    Insert(p->coef, p->exp);
  }
  return *this;
}
const Poly & Poly::operator-=(const Poly & apoly)
{
  for(PolyNode * p = apoly.header; NULL != p;p = p->next) {
    Insert(0 - p->coef, p->exp);
  }
  return *this;
}
const Poly & Poly::operator*=(const Poly & apoly)
{
  *this = (*this * apoly);
  return *this;
}
const Poly operator+(const Poly & poly1, const Poly & poly2)
{
  Poly sum;
  sum += poly1;
  sum += poly2;
  return sum;
}
const Poly operator-(const Poly & poly1, const Poly & poly2)
{
  Poly sum;
  sum += poly1;
  sum -= poly2;
  return sum;
}
const Poly operator*(const Poly & poly1, const Poly & poly2)
{
  Poly ans;
  for(Poly::PolyNode * p = poly1.header; NULL != p;p = p->next) {
    for(Poly::PolyNode * p2 = poly2.header; NULL != p2; p2 = p2->next) {
      ans.Insert((p->coef)*(p2->coef),p->exp+p2->exp);
    }
  }
  return ans;
}

std::ostream & operator<<(std::ostream & os, const Poly & apoly) {
  Poly::PolyNode *p = apoly.header;
  if (NULL == p) {
    os << 0;
    return os;
  }
  for(; NULL != p; p = p->next) {
    if (p != apoly.header)
      os << ((p->coef > 0)?" + ":" ");

    // 系数为0的项目,不写x
    if (0 == p->exp) {
      os << p->coef;
      continue;
    }

    // 系数为1的项目省略不写1
    if (1 != p->coef && -1 !=p->coef)
      os << p->coef;

    // 修正-1不写-的
    if (-1 == p->coef)
      os << "-";

    os << "X";
    // 处理系数为1的情况
    if (1 != p->exp)
   	os <<"^("<< p->exp << ")";
  }
  return os;
}
std::istream & operator>>(std::istream & is, Poly & apoly) {
  using std::cout;
  using std::endl;
  cout << "说明:\n\
    依次输入系数,幂次(只支持整数).以空白字符分隔.\n\
    输入非法字符(字母或者其他非数值字符)或者系数为0,输入结束.\n";
  int coef = 0;
  int exp = 0;

  while(true) {
    if (!(is>>coef)) break;
    if (0 == coef) break;
    if (!(is>>exp)) break;
    apoly.Insert(coef, exp);
  }
  if(is.bad()) {
    cout << "键入了非法字符!\n";
    is.clear();
    while('\n' != is.get());
  }
  return is;
}
