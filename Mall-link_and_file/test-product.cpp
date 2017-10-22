// C++ file
#include<iostream>
#include"product.h"

void prt(const Product & p) {
  using std::endl;
  std::cout << "---------------\n";
  std::cout << "name:" << p.name() << endl
    << "brand:" << p.brand() << endl
    << "price:" << p.price() << endl
    << "quantity:" << p.quantity() << endl;
}
int main(void){
  Product a;
  Product b;
  prt(a);
  prt(b);

  std::cout << "XXXXXXXXXXXXXXX\n";
  int  n = 4;
  std::string str[4];
  str[0] =  "";
  str[1] =  "HI";
  str[2] = "hh";
  str[3] = "z\
	    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\
	    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\
	    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\
	    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\
	    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\
	    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\
	    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
  std::cout << "XXXXXXXXXXXXXXX\n";
  for(int i = 0; i < n; i++) {
    if (a.set_name(str[i]))
      prt(a);
    if (a.set_brand(str[i]))
     prt(a);
  }
  b = a;
  std::cout << a;
  a.set_price(112);
  prt(a);
  prt(b);
  return 0;
}
