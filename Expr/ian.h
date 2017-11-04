#ifndef IAN_INCLUDE_H
#define IAN_INCLUDE_H
char LineAchar(void);
bool YesOrNo(const char * msg);
bool EnterQ(void);

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
