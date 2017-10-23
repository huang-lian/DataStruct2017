// C++ file
/* 库存管理模型
 * Author:huang_lian@126.com
 * date:2017年10月22日10:51:56
 * */
#ifndef MALL_LINK_H
#define MALL_LINK_H
#include<fstream>
#include"product.h"
class Mall{
  public:
    // 完成信息的恢复
    Mall(void);
    Mall(const char * file_name);
    Mall(const Mall & store);
    ~Mall(void);

    void CreateList(const char * file_name = "mall_data.mall");
    void StartBusiness(const char * file_name = "mall_data.mall");
    void Stock(void);
    void Pick(void);
    void Search(void);
    void Update(void);
    void StopBusiness(const char * file_name = "mall_data.mall");

  private:
    struct Appliances{
      Product app;
      struct Appliances * next;
    };
    bool SetAppName(Product &app);
    bool SetAppBrand(Product &app); 
    bool SetAppPrice(Product &app);
    bool SetAppNum(Product &app);
    bool SetProuct(&app);
    Appliances *GetAlterList(const Product & alter_goods);
    size_t ShowAlterList(const Appliances *alter_list);
    Appliances *Free(Appliances*  list);
    bool Insert(const Product & app);
    bool Delete(const Product & app);

    Appliances * app_list_;

};
#endif //MALL_LINK_H
