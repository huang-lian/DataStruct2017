// C++ file
/* 库存管理模型中的商品结构
 * Author:huang_lian@126.com
 * Date:2017-10-22 09:16:18
 * */
#ifndef MALL_PRODUCT_H
#define MALL_PRODUCT_H
#include<string>
class Product{
  public:
    Product(void);
    Product(const Product & goods);
    ~Product(void);
    const Product & operator=(const Product & goods);

    bool set_name(std::string & new_name);
    bool set_brand(std::string & new_barnd);
    bool set_price(float new_price);
    bool set_quantity(size_t new_quantity);

    //bool set_id(void);

    const std::string & name(void) const {return name_;};
    const std::string & brand(void) const {return brand_;};
    float price(void) const {return price_;};
    size_t quantity(void) const {return quantity_;};

    bool operator==(const Product & goods) const;
    bool operator!=(const Product & goods) const;
  private:
    //size_t id_;
    std::string name_;
    std::string brand_;
    float price_;
    size_t quantity_;
};
Product::Product(void) {
  price_ = 0.0;
  quantity_ = 0;
}

Product::Product(const Product & goods) {
  name_ = goods.name_;
  brand_ = goods.name_;
  price_ = goods.price_;
  quantity_ = goods.quantity_;
}

Product::~Product(void) {
}

const Product & Product::operator=(const Product & goods) {
  name_ = goods.name_;
  brand_ = goods.name_;
  price_ = goods.price_;
  quantity_ = goods.quantity_;
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
#endif // MALL_PRODUCT_H
