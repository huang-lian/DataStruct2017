// C++ file
/* 库存管理模型
 * Author:huang_lian@126.com
 * date:2017年10月22日10:51:56
 * */
#ifndef MALL_LINK_H
#define MALL_LINK_H
#include"product.h"
class Mall{
  public:
    Mall(const char * file_name = "mall_data.txt");
    Mall(const Mall & store);
    ~Mall(void);
    bool Insert(const Product & pro);
  :  bool search(const Product & pro);


#endif MALL_LINK_H
