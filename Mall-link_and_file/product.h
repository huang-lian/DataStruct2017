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

    bool set_name(const char * new_name = NULL);
    bool set_brand(const char * new_barnd = NULL);
    bool set_price(float new_price = -1);
    bool set_quantity(size_t new_quantity = (size_t)-1);

    //bool set_id(void);

    const std::string & name(void)const {return name_;};
    const std::string & brand(void) const {return brand_;};
    float price(void)const  {return price_;};
    size_t quantity(void) const{return quantity_;};

    const Product  & operator+=(const Product & goods);
    const Product & operator-=(const Product & goods);

    bool operator==(const Product & goods) const;
    bool operator<(const Product & goods) const;
    friend std::ostream& operator << (std::ostream &os, Product & goods);
    friend std::istream &operator>>(std::istream & is, Product & goods);
  private:
    //size_t id_;
    std::string name_;
    std::string brand_;
    float price_;
    size_t quantity_;
};
#endif // MALL_PRODUCT_H
