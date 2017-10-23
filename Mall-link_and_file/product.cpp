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

bool Product::set_name(std::string & new_name) {
  if (0 >= new_name.size() || 255 < new_name.size())
    return false;
  name_ = new_name;
  return true;
}

bool Product::set_brand(std::string & new_barnd) {
  if (0 >= new_barnd.size() || 255 < new_barnd.size())
    return false;
  brand_ = new_barnd;
  return true;
}

bool Product::set_price(float new_price) {
  if (0>price_)
    return false;
  price_ = new_price;
  return true;
}

bool Product::set_quantity(size_t new_quantity) {
  if (quantity_ == new_quantity)
    return false;
  quantity_ = new_quantity;
  return true;
}

bool Product::operator==(const Product & goods) const {
  if(name_ != goods.name_) return false;
  if(brand_ != goods.brand_) return false;
  return true;
}
bool Product::operator!=(const Product & goods) const {
  return !((*this)== goods);
}
std::ostream & operator << (std::ostream &os, Product & goods) {
  os << goods.name_ <<"\t" << goods.brand_ << "\t" << goods.price_ << "\t" << goods.quantity_;
  return os;
}
std::istream & operator>>(std::istream & is, Product & goods) {
  is >> goods.name_  >> goods.brand_ >>  goods.price_ >>  goods.quantity_;
    return is;
}
