//C++ file
/* 库存管理系统
 * 版本0
 * */
#include<iostream>
#include<fstream>
#include"mall.h"
#include"ian_include.h"
void CommenceBusiess(const char * work_file);
int main(void)  {
  using namespace std;
  const char * work_file = "mall_data.mall";
  const char * loadmsg ="是否加载已有的库存表?(y/n):";
  const char * mkmsg = "是否建立新表?(y/n):";

  ofstream fin;
  fin.open(work_file,ios::in);
   Mall store;
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

      store.CreateList(work_file);
      store.StopBusiness(work_file);

    }
  } else {
    cout << "未检测到库存表\n需要建立库存表才可以继续运行.\n";

    // 不建立则退出
    if (!YesOrNo(mkmsg)) {
      cout << "退出程序!\n";
      return 0;
    }

    store.CreateList(work_file);
    store.StopBusiness(work_file);
  }

  CommenceBusiess(work_file);
  return 0;
}

// 开始工作
void CommenceBusiess(const char * work_file){
  Mall store(work_file);
  char ch = 1;
  while(0 != ch) {
    std::cout <<"库存管理\n\
      A.进货\n\
      B.出货\n\
      C.查询\n\
      D.更新产品信息\n\
      Q.结束营业\n\
      输入相应选项编号选择功能:";

    ch = LineAchar();
    std::cout <<"# choice #" << ch << std::endl;
    switch(ch) {
      case '1':
      case 'a':
      case 'A': store.Stock(); break;
      case '2': 
      case 'b':	
      case 'B': store.Pick(); break;
      case '3': 
      case 'c': 
      case 'C': store.Search(); break;
      case '4': 
      case 'd':
      case 'D': store.Update(); break;
      case '0':
      case 'q': 
      case 'Q': store.StopBusiness(work_file);
		ch = 0;	break;
      default:
		std::cout << "无该选项,请重新输入选择!\n";
    }
  }
}
