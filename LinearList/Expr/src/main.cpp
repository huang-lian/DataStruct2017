#include<iostream>
#include"expr.h"
#include"ian.h"
int main(void)
{
  using namespace std;
  //Expr a("(-5)+(11)-34*(1-(-5))%12-2.34");
  Expr a("3+5/2");
  a.DisPlay();
  Expr::Limits();
  while(!EnterQ()) {
    cout << " 请输入你的表达式:\n";
    cin >> a;
    if(a.is_valid())
      a.DisPlay();
    else
      cout << "输入的表达式不合法!\n";
  }
  return 0;
}
