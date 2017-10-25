#include<iostream>
#include"product.h"
Product::Product(void) {
  price_ = 0.0;
  quantity_ = 0;
}

Product::Product(const Product & goods) {
  name_ = goods.name_;
  brand_ = goods.brand_;
  price_ = goods.price_;
  quantity_ = goods.quantity_;
}

Product::~Product(void) {
}

const Product & Product::operator=(const Product & goods) {
  if (&goods == this)
    return *this;
  name_ = goods.name_;
  brand_ = goods.brand_;
  price_ = goods.price_;
  quantity_ = goods.quantity_;
  return *this;
}

bool Product::set_name(const char * new_name) {
  if (NULL != new_name)
  {
  name_ = new_name;
  return true;
  }
  std::cout << "商品名:";
  std::cin >> name_;
  std::cin.get();
  if (0 >= name_.size() || 255 < name_.size())
    return false;
  return true;
}

bool Product::set_brand(const char * new_barnd) {
  if (NULL != new_barnd) 
  {
    brand_ = new_barnd;
    return true;
  }

  std::cout << "品牌名:";
  std::cin >> brand_;
  std::cin.get();
  if (0 >= brand_.size() || 255 < brand_.size())
    return false;
  return true;
}

bool Product::set_price(float new_price) {
  if(new_price > 0)
  {
  price_ = new_price;
  return true;
  }
  std::cout << "价格:";
  if(!(std::cin >> price_))
  {
    std::cin.clear();
    while('\n' != std::cin.get());
    return false;
  }
  std::cin.get();
  if(0 > price_)
    return false;
  return true;
}

bool Product::set_quantity(size_t new_quantity) {
  if ((size_t)-1 != new_quantity)
  {
    quantity_ = new_quantity;

    return true;
  }
  int n = 0;
  std::cout << "数量:";
  if(!(std::cin >> n)){
    std::cin.clear();
    while(std::cin.get()!='\n');
    return false;
  }
  std::cin.get(); // 处理尾巴字符
  if (n < 0)
    return false;
  quantity_ = n;
  return true;
}
const Product & Product::operator+=(const Product & goods) {
  quantity_ += goods.quantity_;
  return *this;
}
const Product & Product::operator-=(const Product & goods) {
  quantity_ -= goods.quantity_;
  return *this;
}
bool Product::operator<(const Product & goods) const {
  return price_ < goods.price_;
}
bool Product::operator==(const Product & goods) const {
  if (goods.name_ != name_) return false;
  if (goods.brand_ != brand_) return false;
  if (price_- goods.price_ > 10e-6
     || price_- goods.price_ < -10e-6)
    return false;
  return true;
}

std::ostream & operator << (std::ostream &os, Product & goods) {
  os << goods.name_ <<"\t" << goods.brand_ << "\t" << goods.price_ << "\t" << goods.quantity_;
  return os;
}
std::istream & operator>>(std::istream & is, Product & goods) {
  is >> goods.name_  >> goods.brand_ >>  goods.price_ >>  goods.quantity_;
    return is;
}
