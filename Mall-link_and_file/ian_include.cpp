#include<iostream>
#include"ian_include.h"
int InPutN(const char * err_msg) {
  int n;
  while(!(std::cin >> n)){
    std::cin.clear();
    if (NULL != err_msg)
      std::cout << err_msg;
    while(std::cin.get() != '\n');
  }
  std::cin.get();  // deal end char
  return n;
}
/*
 * 读取一行的第一个字符
 * 余下的字符,舍弃(不在缓存区)
 * 换行符号也被读入
 * */
char LineAchar(void)
{
  char ch;
  std::cin.get(ch);
  while('\n'!=ch && std::cin.get() != '\n');
  return ch;
}
bool EnterQ(void)
{
  std::cout << "任意输入继续,q_enter退出";
  char ch = LineAchar();
  return  ('q' == ch || 'Q' == ch);
}

bool YesOrNo(const char * msg)
{  
  char ch;
  while(true) {
    std::cout << msg;
    ch = LineAchar();
    switch(ch) {
      case '1':
      case 'y':
      case 'Y': return true;
      case '0':
      case 'n':
      case 'N':
      case 'q':
      case 'Q': return false;
    }
  }
}
