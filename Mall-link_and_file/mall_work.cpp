#include<iostream>
#include<fstream>
#include"mall_work.h"
#include"ian_include.h"

using std::cout;
using std::endl;
const char * err_in_msg = "输入错误,请重新输入!\n";
// 功能接口
bool MallWork::Init(const char * file_name)
{/*{{{*/
  const char * work_file = file_name;
  const char * loadmsg ="是否加载已有的库存表?(y/n):";
  const char * mkmsg = "是否建立新表?(y/n):";

  std::ofstream fin;
  fin.open(work_file,std::ios::in);
  // 检测是否有可执行的表
  cout << "需要使用库存表才可以继续运行本程序\n";
  if (fin.is_open()) {
    cout << "检测到以下库存表:\n" << work_file 
      << endl;
    fin.close();
    // 不加载则默认退出程序
    if (!YesOrNo(loadmsg)) {
      // 不建立则退出
      if (!YesOrNo(mkmsg)) {
	cout << "退出程序!\n";
	return 0;
      }
    }
    else{
      Read(work_file);
      return 1;
    }
  } else {
    cout << "未检测到库存表\n需要建立库存表才可以继续运行.\n";
    // 不建立则退出
    if (!YesOrNo(mkmsg)) {
      cout << "退出程序!\n";
      return 0;
    }
  }
  Create(work_file);
  return 1;
}/*}}}*/

void MallWork::Stock(void)
{/*{{{*/
  Product goods;
  const char * msg="没该货物,是否继续?(Y/N)";
  AppNode * search_reult = NULL;
  ShowLink(store_);
  do{
    search_reult = NULL;

    cout << "------------------------\n\
      进货引导\n----------------------\n";
    cout << "请按照提示键入信息.\n";
    // 键入正确商品名
    while(!goods.set_name())
    {
      cout << err_in_msg;
    }
    search_reult = SameName(goods);
    while(!goods.set_quantity())
    {
      cout << err_in_msg;
    }
    if((NULL == search_reult)&& YesOrNo(msg))
    {
      while(!goods.set_brand())
      {
	cout << err_in_msg;
      }
      while(!goods.set_price())
      {
	cout << err_in_msg;
      }
      if(Insert(goods))
      {
	cout << "进货成功,进货产品为:\n";
	cout << goods << endl;
      }
      else
      {
	cout << "异常错误,联系管理\n";
      }
    } 
    else 
    {
      cout << "进货前该产品数量为:\n";
      cout << search_reult ->app << endl;
      search_reult->app += goods;
      cout << "进货成功,进货后产品为:\n";
      cout << search_reult->app<< endl;;
    }
  }while(!EnterQ());
  cout << "------------------------\n";
}/*}}}*/
void MallWork::Pick(void)
{/*{{{*/
  Product goods;
  const char * err_in_msg = "输入错误,请重新输入!\n";
  AppNode * search_reult = NULL;
  ShowLink(store_);
  while(!EnterQ())
  {
    search_reult = NULL;

    cout << "------------------------\n\
      提货引导\n----------------------\n";
    cout << "请按照提示键入信息.\n";
    // 键入正确商品名
    while(!goods.set_name())
    {
      cout << err_in_msg;
    }
    search_reult = SameName(goods);
    while(!goods.set_quantity())
    {
      cout << err_in_msg;
    }


    if((NULL == search_reult))
    {
      cout << "无该货物,无法提货";
    }
    else if (search_reult->app.quantity() < goods.quantity())
    {
      cout << "提货目标无法满足!\n";
      cout << "商品: " << search_reult->app.name() << endl;
      cout << "库存: " << search_reult->app.quantity() << endl;
      cout << "目标: " << goods.quantity() << endl;
    }
    else
    {
      cout << "提货前该产品数量为:\n";
      cout << search_reult ->app << endl;
      search_reult->app -=goods;
      cout << "提货后产品为:\n";
      cout << search_reult->app;
    }
  }
}/*}}}*/
void MallWork::Search(void)
{/*{{{*/
  ShowLink(store_);
  char ch = 1;
  while(0 != ch)
  {
    std::cout <<"==================\n\
      查询选择\n\
      A.按照商品名\n\
      B.按照品牌\n\
      C.按照价格区间\n\
      D.按照库存\n\
      Q.回到营业\n\
      输入相应选项编号选择功能:";

    ch = LineAchar();
    std::cout <<"# choice #" << ch << std::endl;
    switch(ch) {
      case '1':
      case 'a':
      case 'A': SeachAtName(); break;
      case '2': 
      case 'b':	
      case 'B': SeachAtBrand(); break;
      case '3': 
      case 'c': 
      case 'C': SeachAtPrice(); break;
      case '4':
      case 'd':
      case 'D': SeachAtStore(); break;
      case '0':
      case 'q': 
      case 'Q': ch = 0;	break;
      default:
		std::cout << "无该选项,请重新输入选择!\n";
    }
  }
}/*}}}*/

MallWork::MallWork(const char * work_file)
{/*{{{*/
  Init(work_file);
}/*}}}*/

MallWork::MallWork(void)
{/*{{{*/
  store_ = NULL;
}/*}}}*/

MallWork::MallWork(const MallWork & mlwork)
{/*{{{*/
  SetStore(mlwork);
}/*}}}*/

MallWork::~MallWork(void)
{/*{{{*/
  store_ = Free(store_);
}/*}}}*/

MallWork & MallWork::operator=(const MallWork & mlwork)
{/*{{{*/
  if (&mlwork == this)
    return *this;
  store_ = Free(store_);
  SetStore(mlwork);
  return *this;
}/*}}}*/


// 合并opertor= 和 拷贝构造函数部分公共代码.
void MallWork::SetStore(const MallWork & mlwork)
{/*{{{*/
  AppNode * p = mlwork.store_;
  AppNode * pre = NULL;
  AppNode * new_node;
  if (NULL != p) {

    new_node = new AppNode;
    new_node-> app = p->app;
    store_ = new_node;
    pre = new_node;
  }
  for(p = mlwork.store_; NULL != p; p = p->next)
  {
    AppNode * new_node = new AppNode;
    new_node-> app = p->app;
    pre->next = new_node;
    pre = new_node;
  }
}/*}}}*/



void MallWork::SeachAtName(void)
{/*{{{*/
  Product goods;
  AppNode * search_reult = NULL;
  do{
  cout << "请输入";
  if(goods.set_name())
  {
    cout << "查找结果如下:\n";
    search_reult = SameName(goods);
    if(NULL != search_reult)
    {
      cout << search_reult->app;
    }
  } else {
    cout << "输入不合法!\n";
  }
  }while(EnterQ());

}/*}}}*/
void MallWork::SeachAtBrand(void)
{/*{{{*/
  Product goods;
  AppNode * p;
  do{
    cout << "请输入";
    if(goods.set_brand())
    {
      cout << "查找结果如下:\n";
      int cnt = 0;
      for(p = store_; NULL != p; p = p->next)
      {
	if(p->app.brand() == goods.brand())
	{
	  cout << p->app << endl;
	  cnt ++;
	}
      }
      cout << "数量" << cnt << endl;
    } else {
      cout << "输入不合法!\n";
    }
  }while(EnterQ());

}/*}}}*/

void MallWork::SeachAtPrice(void) const
{/*{{{*/
  Product max;
  Product min;
  cout << "按照价格查询\n";
  cout << "需要输入上限和下限来查找\n";
  while(!EnterQ())
  {
    cout << "请输入价格上限";
    while(! max.set_price())
    {
      cout << err_in_msg;
      cout << "请输入价格上限";
    }
    cout << "请输入价格下限";
    while((!min.set_price()) || max < min)
    {
      cout << err_in_msg;
      cout << "请输入价格下限";
    }
    cout << "查找结果如下:\n";
    int cnt = 0;
    for(AppNode* p = store_; NULL != p; p = p->next)
    {
      if(min < p->app && p->app < max) 
      {
	cout << p->app << endl;
	cnt ++;
      }
    }
    cout << "数量" << cnt << endl;
  }
}/*}}}*/

void MallWork::SeachAtStore(void) const
{/*{{{*/
  Product max;
  Product min;
  cout << "按照库存查询\n";
  cout << "需要输入库存上限和下限来查找\n";
  while(!EnterQ())
  {
    cout << "请输入库存上限";
    while(! max.quantity())
    {
      cout << err_in_msg;
      cout << "请输入库存上限";
    }
    cout << "请输入库存下限";
    while((!min.quantity())||max.quantity() < min.quantity())
    {
      cout << err_in_msg;
      cout << "请输入库存下限";
    }
    cout << "查找结果如下:\n";
    int cnt = 0;
    for(AppNode *p = store_; NULL != p; p = p->next)
    {
      if (min.quantity() <= p->app.quantity()
	  && p->app.quantity() <= max.quantity())
      {
	cout << p->app << endl;
	cnt ++;
      }
    }
    cout << "数量" << cnt << endl;
  }
}/*}}}*/
void MallWork::Update(void)
{/*{{{*/
  ShowLink(store_);
  char ch = 1;
  while(0 != ch)
  {
    std::cout <<"==================\n\
      更新选择选择\n\
      A.添加产品\n\
      B.删除产品\n\
      C.修改产品信息\n\
      Q.回到营业\n\
      输入相应选项编号选择功能:";

    ch = LineAchar();
    std::cout <<"# choice #" << ch << std::endl;
    switch(ch) {
      case '1':
      case 'a':
      case 'A': Create(); break;
      case '2': 
      case 'b':	
      case 'B': Del(); break;
      case '3': 
      case 'c': 
      case 'C': Change(); break;
      case '0':
      case 'q': 
      case 'Q': ch = 0;
      default:
		std::cout << "无该选项,请重新输入选择!\n";
    }
  }

}/*}}}*/

void MallWork::Del(void)
{/*{{{*/
  Product goods;
  AppNode * search_reult;
  do{
  cout << "请输入";
  if(goods.set_name())
  {
    cout << "查找结果如下:\n";
    search_reult = SameName(goods);
    if(NULL != search_reult)
    {
      cout << search_reult->app;
      Delete(goods);
      cout << "***已删除***\n";
    }
  } else {
    cout << "输入不合法!\n";
  }
  }while(EnterQ());

}/*}}}*/

void MallWork::Change(void)
{/*{{{*/
  Product goods;
  AppNode * search_reult;
  do{
  cout << "请输入";
  if(goods.set_name())
  {
    cout << "查找结果如下:\n";
    search_reult = SameName(goods);
    if(NULL != search_reult)
    {
      cout << search_reult->app;
      cout << "输入新值\n";
      while(!goods.set_brand())
      {
	cout << err_in_msg;
      }
      while(!goods.set_price())
      {
	cout << err_in_msg;
      }
      cout << "***已修改***\n";
    } else
    {
      cout << "没有该产品,无法修改!\n";
      continue;
    }
  } else {
    cout << "输入不合法!\n";
  }
  }while(EnterQ());


}/*}}}*/

void MallWork::Stop(const char * file_name)
{/*{{{*/
  cout << "------------------------\n\
    结束工作,保存信息中\n----------------------\n";
  std::ofstream fout(file_name);
  AppNode * p = store_;
  size_t count = 0;
  while(NULL != p){
    fout << p->app << std::endl;
    p = p->next;
    count ++;
  }
  fout.close();
  cout << "共项目:" << count << std::endl;
}/*}}}*/

void MallWork::Read(const char * file_name)
{/*{{{*/
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
  std::cout << "一共录入  " << count_add << "项目 \n";

}/*}}}*/

void MallWork::Create(const char * work_file)
{/*{{{*/
  Product goods;
  size_t count_add = 0;
  const char * err_in_msg = "输入错误,请重新输入!\n";
  do{

    cout << "------------------------\n\
      库存添加引导\n";
    cout << "请按照提示键入信息.\n";
    while(!goods.set_name())
    {
      cout << err_in_msg;
    }
    while(!goods.set_brand())
    {
      cout << err_in_msg;
    }
    while(!goods.set_price())
    {
      cout << err_in_msg;
    }
    while(!goods.set_quantity())
    {
      cout << err_in_msg;
    }

    if(Insert(goods)) {
      cout << "已添加\n" << goods << endl;/*{{{*/
      count_add ++;/*}}}*/
    } else {
      cout << goods<<"和已有同品牌同名产品冲突,添加失败.\n" << endl;
    }
  }
  while(!EnterQ());
  cout << "共添加项数:" << count_add  << endl;
  cout << "----------------------\n";
  if (NULL != work_file)
  Stop(work_file);
}/*}}}*/


/* 正常过程,插入一个新值,返回
 * 可选过程,同类值合并
 * 异常过程,矛盾值冲突.直接失败.
 * */
bool MallWork::Insert(const Product & goods)
{/*{{{*/

  AppNode * new_node  = new AppNode;
  new_node->app = goods;

  // 空表,直接添加
  if (NULL == store_) {
    new_node->next = store_;
    store_ = new_node;
    return true;
  }

  // 检查是否有同主键值信息,
  // 同键值,检查是否矛盾,
  AppNode * cmp = SameName(goods);
  if(NULL != cmp)
  {
    delete new_node;

    if(goods == cmp->app) { // 信息无冲突,添加
      cmp->app += goods;
      return true;
    } else {
      return false;
    }
  }

  // 新加入商品最廉价
  if (goods < store_->app) {
    new_node->next = store_;
    store_ = new_node;
    return true;
  }

  // 查找最后一个价格低于goods的商品
  AppNode * prelow = store_;
  AppNode * plow = prelow->next;
  for(;NULL != plow && plow->app < goods; plow = plow->next) {
    prelow = plow;
  }
  new_node->next = prelow->next; 
  prelow->next = new_node;
  return true;
}/*}}}*/

bool MallWork::Delete(const Product & goods)
{/*{{{*/
  AppNode *cmp =NULL;
  AppNode **ppre_cmp = &cmp;
  cmp = SameName(goods,ppre_cmp);
  if (NULL == cmp)
    return false;

  if (cmp == store_) {
    store_ = store_->next;
  } else {
    (*ppre_cmp)->next = cmp->next;
  }
  delete cmp;
  return true;
}/*}}}*/


MallWork::AppNode * MallWork::SameName(const Product & goods, MallWork::AppNode **save_ppre)
{/*{{{*/
  if (NULL != save_ppre)
    *save_ppre = store_;
  AppNode * cmp = store_;
  for(cmp = store_; NULL != cmp && cmp->app.name() != goods.name(); cmp = cmp->next){
    if(NULL != save_ppre)
      *save_ppre = cmp;
  }
  return cmp;
}/*}}}*/


MallWork::AppNode * MallWork::Free(MallWork::AppNode *p)
{/*{{{*/
  AppNode * pre = NULL;
  while(NULL != p)
  {
    pre = p;
    p = p->next;
    delete pre;
  }
  return NULL;
}/*}}}*/

int MallWork::ShowLink(MallWork::AppNode *header)
{/*{{{*/
  AppNode *p = header;
  std::cout << "商品信息如下:\n";
  int cnt = 0;
  for(p = store_;NULL != p; p = p->next)
  {
    std::cout << p->app << endl;
    cnt ++;
  }
  std::cout << "累计:" << cnt << std::endl;
  return cnt;

}/*}}}*/
