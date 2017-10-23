#ifndef IAN_INCLUDE_H
#define IAN_INCLUDE_H
char LineAchar(void);
bool YesOrNo(const char * msg);
bool EnterQ(void);
int InPutN(const char * err_msg=NULL);

int InPutN(const char * err_msg) {
  int n;
  while(!(std::cin >> n)){
    std::cin.clear();
    if (NULL != msg)
      std::cout << msg;
    while(std::cin.get() != '\n');
  }
  std::cin.get();  // deal end char
}
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
#endif // IAN_INCLUDE_H
