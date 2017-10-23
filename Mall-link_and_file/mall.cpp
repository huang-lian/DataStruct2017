#include<iostream>
#include"mall.h"
#include"ian_include.h"

bool Mall::SetAppName(Product &app) {/*{{{*/
  std::cout << "商品名称:";
  std::string name;
  std::cin >> name;
  return app.set_name(name);
}/*}}}*/
bool Mall::SetAppBrand(Product &app) {/*{{{*/
  std::cout << "品牌";
  std::string brand;
  std::cin >> brand;
  return app.set_brand(brand);
}/*}}}*/
bool Mall::SetAppNum(Product &app) {/*{{{*/
  int n;
  using std::cout;
  using std::cin;
  cout << "数量";
  while(!(cin >> n)){
    cin.clear();
    while(cin.get() != '\n');
  }
  return ( n >= 0) && app.set_quantity(n);
}/*}}}*/
bool Mall::SetAppPrice(Product &app) {/*{{{*/
  float price;
  std::cout << "价格:";
  std::cin >> price;
  return app.set_price(price);
}/*}}}*/
bool Mall::SetProuct(Product &app) {/*{{{*/
    cout << "依次键入商品名称 品牌 价格 数量\n";
    if (!SetAppName(app)) {
      cout << "商品名错误!";
      return false;
    }
    if (!SetAppBrand(app)) {
      cout << " 品牌不符合规范";
      return false;
    }
    if (!SetAppPrice(app)) {
      cout << "价格错误\n";
      return false;
    }
    if (!SetAppPrice(app)) {
      // #fix
      cout << "num\n";
      continue;
    }
    return true;

}/*}}}*/
Mall::Appliances *GetAlterList(const Product & alter_goods) {/*{{{*/
  // 筛选出同名电器.存入备选表
  Appliances * alter_list = NULL;
  for(Appliances * p = app_list_; NULL != p; p = p->next) {
    if(p->app.name() == alter_goods.name()) {
      Appliances * pnew_alter = new Appliances;
      pnew_alter->app = p->app;
      pnew_alter->next = alter_list;
      alter_list = pnew_alter;
    }
  }
  return alter_list;
}/*}}}*/

size_t ShowAlterList(const Mall::Appliances *alter_list) {/*{{{*/
  std::cout << "该类商品信息如下:\n";
  size_t cnt = 0;
  for(Appliances *p = alter_list; NULL != p; p = p->next) {
    cnt++;
    std::cout << cnt << p->app << std::endl;
  }
  std::cout << "同名商品数: " << cnt << std::endl;
  return cnt;
}/*}}}*/

Mall::Appliances * Mall::Free(Appliances * list) {/*{{{*/
  Appliances * p = NULL;
  while(NULL != list) {
    p = list;
    list = list->next;
    delete p;
  }
  return list;
}/*}}}*/

Mall::Mall(void) {/*{{{*/
  app_list_ = NULL;
}/*}}}*/
Mall::Mall(const char * file_name) {/*{{{*/
  StartBusiness(file_name);
}/*}}}*/

Mall::Mall(const Mall & store) {
  // #pass
}

Mall::~Mall(void) {/*{{{*/
  app_list_ = Free(app_list_);
}/*}}}*/
void Mall::CreateList(const char * file_name) {/*{{{*/
  using std::cout;
  using std::endl;

  std::cout << "建立库存引导\n";

  Product new_goods;
  size_t count_add = 0;
  while(!EnterQ()) {
    if(!SetProuct(new_goods))
      continue;
    if(Insert(new_goods)) {
      cout << "已添加\n" << new_goods << endl;/*{{{*/
      count_add ++;/*}}}*/
    } else {
      cout << new_goods<<"和已有同品牌同名产品冲突,添加失败.\n" << endl;
    }
  }
  cout << "共添加项数:" << count_add  << endl;

}/*}}}*/
void Mall::StartBusiness(const char * file_name) {/*{{{*/
  std::cout << "从文件" << file_name << "导入库存信息,准备营业..\n";
  std::ifstream fin;
  fin.open(file_name,std::ios::in);
  if(!fin.is_open()) {
    std::cout << "文件错误" << std::endl;
  }
  Product app;
  size_t count_add = 0;
  while(!fin.eof()){
    fin>>app;
    Insert(app);
    count_add ++;
  }
  fin.close();
  // #fix
  std::cout << "dao  " << count_add << " \n";
}/*}}}*/

void Mall::Stock(void) {/*{{{*/
  using std::cin;
  using std::cout;
  using std::endl;
  std::cout << "进货引导\n";

  const char *msg = "没有该货物,是否进货(y/n)?";
  Product alter_goods;
  char ch;
  size_t count_stock = 0;
  Appliances * alter_list = NULL;   // 备选表
  while(!EnterQ()) {
    alter_list = Free(alter_list);  // 清空备选表
    cout << "依次键入商品名称 品牌 价格 数量\n";
    if (!SetAppName(alter_goods)) {
      cout << "商品名错误!\n";
      continue;
    }

    // 筛选出同名电器.存入备选表
    alter_list = GetAlterList(alter_goods);

    // 展示同名称电器信息并统计数量
    int cnt = ShowAlterList(alter_list);

    if( 0 == cnt && YesOrNo(msg)) // 找不到备选,但是进货,需要输入
      goto ADD_BRAND;
    else 
      continue;

    if(1 == cnt ) {
      alter_goods= alter_list->app;  // 设置品牌和价格
      goto ADD_N;
    }
ADD_BRAND:
    cout << "补充商品品牌\n";
    while(!SetAppBrand(alter_goods)){
      cout << "商品名称不符合标准.(1-255)字符)\n";
    }
    Appliances *p; 
    for(p= alter_list; NULL != p; p = p->next) {
      if (p->app == alter_goods){
	alter_goods = p->app;  // 如果备选里面有,可以直接设置价格
	goto ADD_N;
      }
    }
    if (NULL == p && 1 == YesOrNo(msg))
      goto ADD_N;
    else
      continue;

    cout << "补充商品价格\n";
    while(!SetAppPrice(alter_goods)){
      cout << "价格不合法\n";
    }
ADD_N:
    cout << "补充进货数量\n";
    while(!SetAppNum(alter_goods)){
      cout << "货物数量应当大于0";
    }

    bool ans = Insert(alter_goods);
    if(ans) {
      count_stock ++;
      cout << "已进货:\n" << alter_goods << endl;
    } else {
      cout << alter_goods<<"和已有同品牌同名产品冲突,添加失败.\n" << endl;
    }
  }
  alter_list = Free(alter_list);  // 清空备选表
  cout << "共进货产品: " << count_stock << endl;
}/*}}}*/
void Mall::Pick(void) {/*{{{*/
  std::cout << "提货引导\n";
  using std::cin;
  using std::cout;
  using std::endl;

  const char *msg = "没有该货物,无法提货";
  Product alter_goods;
  char ch;
  Appliances * alter_list = NULL;   // 备选表
  while(!EnterQ()) {
    alter_list = Free(alter_list);  // 清空备选表
    cout << "依次键入商品名称 品牌\n";
    if ((!SetAppName(alter_goods))) {
      cout << "商品名错误!\n";
      continue;
    }

    // 筛选出同名电器.存入备选表
    alter_list = GetAlterList(alter_goods);
    // 展示同名称电器信息并统计数量
    int cnt = ShowAlterList(alter_list);

    if (0 == cnt) {
      cout << msg << endl;
      continue;
    }
    if(1 == cnt ) {
      alter_goods= alter_list->app;  // 设置品牌和价格
      goto ADD_N;
    }
    cout << "补充商品品牌\n";
    if(!SetAppBrand(alter_goods)){
      cout << "商品名称不符合标准.(1-255)字符)\n";
      cout << msg << endl;
      continue;
    }
    Appliances *p;
    for(p= alter_list; NULL != p; p =p->next) {
      if (p->app == alter_goods){
	alter_goods = p->app;  
	goto ADD_N;
      }
    }
    if (NULL == p) {
      cout << msg << endl;
      continue;
    }

ADD_N:
    cout << "请输入提货数量\n";
    if (!SetAppNum(alter_goods)){
      cout << "货物数量应当大于0";
      cout << msg << endl;
      continue;
    } else if( alter_goods.quantity() > p->app.quantity()) {
      cout << "货物数量不够.无法提货" << endl;
      cout << "库存 " << p->app.quantity() << endl;
      cout << "提货目标:" << alter_goods.quantity() << endl;
      continue;
    }

    // 删除旧,插入新的
    alter_goods.set_quantity(p->app.quantity() - alter_goods.quantity());
    Delete(alter_goods);
    Insert(alter_goods);
  }
  Free(alter_list);
}/*}}}*/
void Mall::Search(void) {/*{{{*/
  std::cout << "查询引导:\n";
  using std::cin;
  using std::cout;
  using std::endl;

  const char *msg = "查询不到货物";
  Product alter_goods;
  Appliances * alter_list = NULL;   // 备选表
  while(!EnterQ()) {
    alter_list = Free(alter_list);  // 清空备选表

    cout << "依次键入商品名称 品牌\n";
    if ((!SetAppName(alter_goods))) {
      cout << "商品名错误!\n";
      continue;
    }

    // 筛选出同名电器.存入备选表
    alter_list = GetAlterList(alter_goods);
    // 展示同名称电器信息并统计数量
    int cnt = ShowAlterList(alter_list);

    if (0 == cnt) {
      cout << msg << endl;
      continue;
    }
    if(1 == cnt ) {
      continue;
    }
    cout << "补充商品品牌\n";
    if(!SetAppBrand(alter_goods)){
      cout << "商品名称不符合标准.(1-255)字符)\n";
      continue;
    }
    for(p= alter_list; NULL != p; p =p->next) {
      if (p->app == alter_goods){
	alter_goods = p->app;  
	cout << p->app << endl;
	continue;
      }
    }
    if (NULL == p) {
      cout << msg << endl;
      continue;
    }

  }
  Free(alter_list);
}/*}}}*/
void Mall::Update(void) {
  using std::cin;
  using std::cout;
  using std::endl;

  const char *msg = "查询不到货物";
  Product alter_goods;
  char ch;
  Appliances * alter_list = NULL;   // 备选表
  while(0 != ch) {
    std::cout << "商品信息更新引导\n\
      A.add\n\
      B.Delete\n\
      C.change\n\
      Input you choice:";
    ch = LineAchar();
    switch(ch) {
      case '1';
      case 'a':
      case 'A'; CreateList():
      case '2':
      case 'b':
      case 'B':
      case '3':
      case 'c':
      case 'C':
      case '0':
      case 'q':
      case 'Q': ch = 0;
      default:
		std::cout << "无该选项,请重新输入选择!\n";
    }
  }
  
  while(EnterQ()) {/*{{{*/
    alter_list = Free(alter_list);  // 清空备选表

    cout << "依次键入商品名称 品牌\n";
    if ((!SetAppName(alter_goods))) {
      cout << "商品名错误!\n";
      continue;
    }

    // 筛选出同名电器.存入备选表
    alter_list = GetAlterList(alter_goods);

    // 展示同名称电器信息并统计数量
    int cnt = ShowAlterList(alter_list);

    if (0 == cnt) {
      cout << msg << endl;
      continue;
    }
    if(1 == cnt ) {
      continue;
    }
    cout << "补充商品品牌\n";
    if(!SetAppBrand(alter_goods)){
      cout << "商品名称不符合标准.(1-255)字符)\n";
      continue;
    }
    for(p= alter_list; NULL != p; p =p->next) {
      if (p->app == alter_goods){
	alter_goods = p->app;  
	cout << p->app << endl;
	continue;
      }
    }
    if (NULL == p) {
      cout << msg << endl;
      continue;
    }
  }/*}}}*/
}

void Mall::StopBusiness(const char * file_name) {/*{{{*/
  std::ofstream fout(file_name);
  Appliances * p = app_list_;
  while(NULL != p){
    fout << p->app << std::endl;
    p = p->next;
  }
  fout.close();
}/*}}}*/
bool Mall::Insert(const Product & app) {/*{{{*/
  Appliances * p = app_list_;

  // 检查是否有相同产品,有且价格相同,合并,价格不同矛盾.
  for(p = app_list_; NULL != p && app != p->app; p = p->next) {
  }
  if(NULL != p && app ==p->app){
    if(app.price()- p->app.price() < 10e-6 && app.price()- p->app.price() > -10e-6) {
      p->app.set_quantity(p->app.quantity() + app.quantity());
      return true;
    } else {
      return false;
    }
  }

  Appliances * new_app  = new Appliances;
  new_app->app = app;
  new_app->next = NULL;
  if (NULL == app_list_|| app_list_->app.price() > new_app->app.price()) {
    new_app->next = app_list_;
    app_list_ = new_app;
    return true;
  }


  // 查找第一个不比new_app价格少的
  // 这个节点或者是p或者不存在
  p = app_list_;
  Appliances * pre = p;
  while(NULL != p && p->app.price()< new_app->app.price()) {
    pre = p;
    p=p->next;
  }
  new_app->next = pre->next;
  pre->next = new_app;
  return true;
}/*}}}*/

bool Mall::Delete(const Product & app) {/*{{{*/
  Appliances * p = app_list_;
  Appliances * pre = p;

  // 检查是否有相同产品
  for(p = app_list_; NULL != p && app != p->app; p = p->next) {
    pre = p;
  }
  if (NULL == p)
    return false;
  if(p ==app_list_) {
    app_list_ = app_list_->next;
    delete p;
    return true;
  } 
  pre->next = p->next;
  delete p;
  return true;
}/*}}}*/
