#ifndef EXPR_H
#define EXPR_H
#include<iostream>
class Expr{
  public:
    Expr(void);
    Expr(const char * c_str_expr);
    Expr(const Expr & aexpr);
    ~Expr(void);
    const Expr & operator=(const Expr & aexpr);

    void DisPlay(void) const;
    void ShowInfix(void) const;
    void ShowPostfix(void) const;
    void ShowResult(void) const;

    double value(void) const {return value_;};
    bool is_valid(void) const { return is_valid_;};
    void Clear(void) { is_valid_ = true;};

    static void Limits(void);

    friend std::istream & operator>>(std::istream & is, Expr & aexpr);
    friend std::ostream & operator<<(std::ostream & os, const Expr & aexpr);
  private:
    struct ExprNode{
      union{
	char op;
	int n;
	double d;
      }data;
      int tag;  // 标记存储类型
                // 0 符号
		// 1 int
		// 2 double
      struct ExprNode * next;
    };
    ExprNode * infix_expr_;
    ExprNode * postfix_expr_;
    double value_;
    bool is_valid_;

    void PostInsert(const ExprNode * node, ExprNode *& header);
    void Free(void);
    void Show(ExprNode * header) const;
    void set_infix_expr(const char * c_str_expr);
    void set_postfix_expr(void);
    void set_value(void);

    void CommCopyAndAssign(const Expr & aexpr);

    bool IsDigit(char ch);
    int StrToI(int lhs, int rhs, const char * expr);
    double StrToF(int lhs, int rhs, const char * expr);

    int OpPriority(char op);
};
#endif // EXPR_H
