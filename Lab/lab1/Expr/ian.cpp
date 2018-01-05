#include<iostream>
#include"ian.h"
// 自定义的用于实现一些小操作的函数
char LineAchar(void)
{
  char ch;
  std::cin.get(ch);
  while('\n'!=ch && EOF != ch && std::cin.get() != '\n');
  return ch;
}

bool EnterQ(void)
{
  std::cout << "Q-Enter to quit,and any other key to continue.";
  char ch = LineAchar();
  return  ('q' == ch || 'Q' == ch || EOF == ch);
}

bool YesOrNo(const char * msg)
{  
  char ch;
  while(true) {
    std::cout << msg;
    ch = LineAchar();
    switch(ch) {
      case 'y':
      case 'Y': return true;
      case 'n':
      case 'N': return false;
    }
  }
}
