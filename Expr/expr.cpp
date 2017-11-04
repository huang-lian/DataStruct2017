#include"expr.h"
#include"link_stack.h"
#define MAX_SIZE 256

void Expr::PostInsert(const ExprNode * node, ExprNode  *& header)
{/*{{{*/
  ExprNode * newnode = new ExprNode;
  newnode->data = node->data;
  newnode->tag = node->tag;
  newnode->next = NULL;
  if (NULL == header) {
    header = newnode;
  } else {
    ExprNode * p = header;
    while(NULL != p->next) {
      p = p->next;
    }
    p->next = newnode;
  }
}/*}}}*/

void Expr::Free(void)
{/*{{{*/
  ExprNode * p = infix_expr_;
  while(NULL != infix_expr_) {
    p = infix_expr_;
    infix_expr_ = infix_expr_->next;
    delete p;
  }
  while(NULL != postfix_expr_) {
    p = postfix_expr_;
    postfix_expr_ = postfix_expr_->next;
    delete p;
  }
  value_ = 0;
}/*}}}*/
void Expr::Show(ExprNode * header) const
{/*{{{*/
  using std::cout;
  using std::endl;
  if (!is_valid())
    cout << "表达式异常\n";
  if (NULL == header) {
    cout << 0 << endl;
    return;
  }

  for(ExprNode * p = header; NULL != p; p = p->next) {
    if (0 == p->tag) {
      cout << p->data.op;
    } else if (1 == p->tag) {
      cout << p->data.n;
    } else {
      cout << p->data.d;
    }
    cout << " ";
  }
  cout << endl;
}/*}}}*/

bool Expr::IsDigit(char ch)
{/*{{{*/
  return ('0' <= ch && ch <= '9');
}/*}}}*/
int Expr::StrToI(int lhs, int rhs, const char * expr)
{/*{{{*/
  int sum = 0;
  int sign = 1;
 if( '-' == expr[lhs]) {
   sign = -1;
   lhs ++;
 }

  for(int i = lhs; i <= rhs && '\0' != expr[i]; i ++) {
    if (' ' == expr[i] || '\t' == expr[i])
      continue;
    sum = sum*10 + (expr[i] - '0');
  }
  return sum*sign;
}/*}}}*/

double Expr::StrToF(int lhs, int rhs, const char * expr)
{/*{{{*/
  double sum = 0;
  double frac = 1;
  bool is_float = false;
  int sign = 1;
  if( '-' == expr[lhs]) {
    sign = -1;
    lhs ++;
  }
  for(int i = lhs; i <= rhs && '\0' != expr[i]; i ++) {
    if (' ' == expr[i] || '\t' == expr[i])
      continue;
    if ('.' == expr[i]) {
      is_float = true;
      continue;
    }
    if (is_float) {
      frac /= 10;
      sum = sum + (expr[i]- '0')*frac;
    } else {
      sum = sum*10 + (expr[i] - '0');
    }
  }
  return sum*sign;

}/*}}}*/

void Expr::set_infix_expr(const char * c_str_expr)
{/*{{{*/
  // 先处理合法的表达式
  const char * expr = c_str_expr;   // 缩短长度
  ExprNode *p = new ExprNode;     // 临时存放数据
  int i = 0;               // 作为索引使用
  int num_start_pos = -1;  // 用于保存一个数值的开始下标.
  bool is_float = false;  // 标记一个数是否是浮点数
  int flag_pre = 0;     // 标记当前访问到的字符前一个字符的类型.其中
			// 0 无字符,或者左括号 (
			// 1 数值[0-9]
			// 2 运算符号[+-*/%]
			// 3 取负号
			// 4 小数点
			// 5 右括号
  LinkStack<char> bracket; // 用于验证括号匹配


  // 逐一读入字符,判断表达式的合法性
  for(i = 0; '\0' != expr[i] && i < MAX_SIZE; i++)
  {/*{{{*/
    if (' ' == expr[i] || '\t' == expr[i])
      continue;
    if (IsDigit(expr[i])) {
      flag_pre = 1;
      if(-1 == num_start_pos) {
	num_start_pos = i;
      }
      continue;
    }


    if ('.' != expr[i] && -1 != num_start_pos)
    {/*{{{*/
      if (10 < i - num_start_pos) {
	is_valid_ = false;  // 字符过长
	break;
      }

      if(is_float) {
	p->tag = 2;
	p->data.d = StrToF(num_start_pos, i-1, expr);
      } else {
	p->tag = 1;
	p->data.n = StrToI(num_start_pos, i-1, expr);
      }
      PostInsert(p,infix_expr_);

      is_float = false;
      num_start_pos = -1;
      flag_pre = 1;
    }/*}}}*/

    switch(expr[i])
    {/*{{{*/
      case ' ':
      case '\t': break;
      case '.': if (1 != flag_pre || is_float) {
		  is_valid_ = false;
		} else {
		  flag_pre = 4;  // 合法小数点
		  is_float = true;
		}
		 break;
      case '-':	
		 //if (0 == flag_pre || 2 == flag_pre) {
		 // 一种较为宽松的负号规则
		 
		 if (0 == flag_pre) {
		  flag_pre = 3;
		  num_start_pos = i;   // 作为负数的一部分
		} else if (1 == flag_pre || 5 == flag_pre) {
		  flag_pre = 2;    // 作为减号运算符号
		  p->tag = 0;
		  p->data.op = expr[i];
		  PostInsert(p, infix_expr_);
		} else {
		  is_valid_ = false;
		}
		break;
      case '(': 
		bracket.Push(expr[i]);   // 括号匹配
		if (0 == flag_pre || 2 == flag_pre || 3 == flag_pre) {
		  flag_pre = 0;

		  p->tag = 0;
		  p->data.op = expr[i];
		  PostInsert(p, infix_expr_);
		} else {
		  is_valid_ = false;
		}
		break;
      case ')': 
		if ((!bracket.IsEmpty()) && '(' == bracket.Top()) {
		  bracket.Pop();   // 括号匹配检查
		} else {
		  is_valid_ = false;
		  break;
		}
		if (1 == flag_pre || 5 == flag_pre) {
		  flag_pre = 5;  // 合法括号
		  p->tag = 0;
		  p->data.op = expr[i];
		  PostInsert(p, infix_expr_);
		} else {
		  is_valid_ = false;
		}
		break;
      case '+':
      case '*':
      case '/':
      case '%': if (1 == flag_pre || 5 == flag_pre) {
		  flag_pre = 2;   // 合法运算符号
		  p->tag = 0;
		  p->data.op = expr[i];
		  PostInsert(p, infix_expr_);
		} else {
		  is_valid_ = false;
		}
		break;
      default:
		is_valid_ = false;  // 其他字符
    }/*}}}*/

    //不合法表达式不必继续判断
    if (!is_valid())
      break;

  }/*}}}*/

    


  // 括号不匹配的表达式,不合法
  if(is_valid_ && !bracket.IsEmpty()) {
    is_valid_ = false;
  }

  // 最后一个数值需要添加 到表达式中
  if (is_valid_ && 1 == flag_pre)
  {/*{{{*/
      if(is_float) {
      p->tag = 2;
      p->data.d = StrToF(num_start_pos, i-1, expr);
    } else {
      p->tag = 1;
      p->data.n = StrToI(num_start_pos, i-1, expr);
    }
    PostInsert(p,infix_expr_);

    is_float = false;
    num_start_pos = -1;
    flag_pre = 1;
  
    if (10 < i - num_start_pos) {
      is_valid_ = false;  // 字符过长
    }
  }/*}}}*/
  else if ( 5 != flag_pre)   // 如果表达式结尾的既不是数也不是又括号,非法
  {
    is_valid_ = false;
  }

  // 清除不合法表达式,避免出现非法计算
  if (!is_valid_) {
    Free();
  }

  // 删除临时变量
  delete p;
}/*}}}*/

int Expr::OpPriority(char op)
{/*{{{*/
  switch(op) {
    case '+':
    case '-': return 0;
    case '*': 
    case '/':
    case '%': return 1;
    default:
      return -1;
  }
}/*}}}*/
void Expr::set_postfix_expr(void)
{/*{{{*/
  // 已经确保表达式是合法的
  LinkStack<ExprNode *> op_stack;
  ExprNode *p = infix_expr_;
  for(;NULL != p; p = p->next)
  {/*{{{*/
    if(0 != p->tag) {  // 直接输出操作数
      PostInsert(p, postfix_expr_);
    } else if (op_stack.IsEmpty() || '(' == p->data.op 
	       || OpPriority(p->data.op) > OpPriority(op_stack.Top()->data.op)) { 
      // 操作符号优先级更加高
      op_stack.Push(p);
    } else if (')' == p->data.op) {  // 左右括号匹配
      while('(' != op_stack.Top()->data.op) {
	PostInsert(op_stack.Top(),postfix_expr_);
	op_stack.Pop();
      }
      op_stack.Pop();
    } else { // 栈顶优先级较高的情况
      while((!op_stack.IsEmpty())
	     && OpPriority(p->data.op) <= OpPriority(op_stack.Top()->data.op)) {
	PostInsert(op_stack.Top(),postfix_expr_);
	op_stack.Pop();
      }	
    }
  }/*}}}*/

  // 清空栈中的运算符号
  while(!op_stack.IsEmpty()) {
    PostInsert(op_stack.Top(),postfix_expr_);
    op_stack.Pop();
  }	

}/*}}}*/

void Expr::set_value(void)
{/*{{{*/
  // 已经确保表达式是合法的
  LinkStack<double> num_stack;
  ExprNode *p = postfix_expr_;
  double t;
  for(;NULL != p; p = p->next)
  {
    if (1 == p->tag) {
      num_stack.Push(p->data.n);
    } else if (2 == p->tag) {
      num_stack.Push(p->data.d);
    } else {
      num_stack.Top(t);   // 先弹出的是第二操作数
      num_stack.Pop();
      num_stack.Top(value_);
      num_stack.Pop();
      switch(p->data.op) {
	case '+': value_ += t; break;
	case '-': value_ -= t; break;
	case '*': value_ *= t; break;
	case '/': value_ /= t; break;
	case '%': value_ = int(value_)%int(t); break;
      }
      num_stack.Push(value_);
    }

  }
  num_stack.Top(value_);
}/*}}}*/

void Expr::CommCopyAndAssign(const Expr & aexpr)
{/*{{{*/
 for(ExprNode * p = aexpr.infix_expr_; NULL != p; p = p->next) {
   PostInsert(p,infix_expr_);
 } 
 set_postfix_expr();
 set_value();
 is_valid_ = aexpr.is_valid_;
}/*}}}*/

Expr::Expr(void)
{/*{{{*/
  infix_expr_ = NULL;
  postfix_expr_ = NULL;
  value_ = 0;
  is_valid_ = true;
}/*}}}*/

Expr::Expr(const char * c_str_expr)
{/*{{{*/
  infix_expr_ = NULL;
  postfix_expr_ = NULL;
  value_ = 0;
  is_valid_ = true;

  set_infix_expr(c_str_expr);
  set_postfix_expr();
  set_value();
}/*}}}*/

Expr::Expr(const Expr & aexpr)
{/*{{{*/
  Expr();
  CommCopyAndAssign(aexpr);
}/*}}}*/

Expr:: ~Expr(void)
{/*{{{*/
  Free();
}/*}}}*/

const Expr & Expr::operator=(const Expr & aexpr)
{/*{{{*/
  if ( &aexpr == this)
    return *this;
  Free();
  CommCopyAndAssign(aexpr);
  return *this;
}/*}}}*/


void Expr::DisPlay(void) const
{/*{{{*/
  std::cout << "-----------------------\n";
  ShowInfix();
  ShowPostfix();
  ShowResult();
  std::cout << "-----------------------\n";
}/*}}}*/
void Expr::ShowResult(void) const
{/*{{{*/
  std::cout << "Value = " << value_ << std::endl;
}/*}}}*/
void Expr::ShowInfix(void) const
{/*{{{*/
  std::cout << "Infix Expression:\n";
  Show(infix_expr_);
}/*}}}*/

void Expr::ShowPostfix(void) const
{/*{{{*/
  std::cout << "Postfix Expression:\n";
  Show(postfix_expr_);
}/*}}}*/

void Expr::Limits(void)
{/*{{{*/
  std::cout << "提示:\n\
    - 表达式长度不超过255(含空格字符).\n\
    - Enter 结束输入\n\
    - 错误表达式为0\n\
    - 表达式中运算符号只能包括以下5种:\n\
           + - * / % \n\
    - 表达式中可以包含空格,以及括号( ) \n\
    - 表达式不支持e, pi 等这类符号常数.\n\
    - 表达式中的整数不能超出9位\n\
    - [-] 只能作为负号出现时即:\n\
    	- 需要在后面接一个常数,而是表达式或者(\n\
	- [-]前面不能是运算符号.\n\
下面是一些举例\n\
         -3*(-7+5) // Valid 表示(-3) * ((-7) + 5) \n\
	 4+-1   // InValid \n\
	 5/-2  // InValid \n\
	 12*-3  // InValid \n\
	 -(12-31) // InValid\n";
}/*}}}*/
std::istream & operator>>(std::istream & is, Expr & aexpr)
{/*{{{*/
  char expr[MAX_SIZE] = {0};
  is.getline(expr, MAX_SIZE);
  aexpr = Expr(expr);
  return is;
}/*}}}*/

std::ostream & operator<<(std::ostream & os, const Expr & aexpr)
{/*{{{*/
  os << aexpr.value_;
  return os;
}/*}}}*/
