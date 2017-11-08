//C++ file
/* 库存管理系统
 * 版本0
 * */
#include<iostream>
#include<fstream>
#include"mall_work.h"
#include"ian_include.h"
int main(void) 
{
  MallWork work_;
  const char * kWorkfile = "work_file.mall";
  if(!work_.Init(kWorkfile))
  {

    std::cout << "感谢使用,再见!\n";
    return 0;
  }
  char ch = 1;
  while(0 != ch) {
    std::cout <<"==================\n\
      库存管理\n\
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
      case 'A': work_.Stock(); break;
      case '2': 
      case 'b':	
      case 'B': work_.Pick(); break;
      case '3': 
      case 'c': 
      case 'C': work_.Search(); break;
      case '4': 
      case 'd':
      case 'D': work_.Update(); break;
      case '0':
      case 'q': 
      case 'Q': ch = 0; work_.Stop(kWorkfile);	break;
      default:
		std::cout << "无该选项,请重新输入选择!\n";
    }
  }
  std::cout << "感谢使用,再见!\n";
  return 0;
}

