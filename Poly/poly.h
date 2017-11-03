// C++ file
/*
 * 多项式运算
 * Author:huang_lian@126.com
 * Date:2017年11月01日 星期三
 */

#ifndef POLY_H
#define POLY_H
#include<iostream>
class Poly{
  public:
    Poly(void);
    Poly(int m, int n = 0);
    Poly(const Poly & apoly);
    ~Poly(void);
    const Poly & operator=(const Poly & apoly);

    const Poly & operator+=(const Poly & apoly);
    const Poly & operator-=(const Poly & apoly);
    const Poly & operator*=(const Poly & apoly);
    
    friend const Poly operator+(const Poly & poly1, const Poly & poly2);
    friend const Poly operator-(const Poly & poly1, const Poly & poly2);
    friend const Poly operator*(const Poly & poly1, const Poly & poly2);

    friend std::ostream & operator<<(std::ostream & os, const Poly & apoly);
    friend std::istream & operator>>(std::istream & is, Poly & apoly);

  private:
    struct PolyNode{
      int coef;  // 系数
      int exp;
      struct PolyNode * next;
    };
    struct PolyNode * header;
    
    bool Insert(int coef, int exp = 0);

    void Free(void);
};
#endif // POLY_H
