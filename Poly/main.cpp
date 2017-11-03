#include<iostream>
#include"poly.h"
int main(void)
{
  using namespace std;
  Poly a;
  Poly b(5,3);
  Poly c(4,2);
  cin >>a;
  cout << "a is \n" << a << endl;
  cout << "b is \n" << b << endl;
  cout << "c is \n" << c << endl;
  cout <<" c+b = " << (b+c) << endl;

  cout <<" b*c = " << (b+c)*(b-c) << endl;
  return 0;
}
