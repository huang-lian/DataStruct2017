#include<iostream>
#include<string>
#include"queue_stack.h"
using namespace std;
void Show(QueueStack<string> p)
{
  cout << "栈顶<----->栈底\n";
  if(p.IsEmpty())
    cout << "NULL";
  while(!p.IsEmpty()) {
    cout<< p.Top() << "\t";
    p.Pop();
  }
  cout << endl;
}
int main(void) {
  QueueStack<string> st;
  string n;
  int ch = 1;
  char err_in;
  cout << "start#\n";
  while(0 != ch) {
    Show(st);
    cout << "\t0.exit\t1.Push\t-1.Pop\t2.Top\n";
    while(!(cin >> ch))
    {
      cin.clear();
      do{
	cin.get(err_in);
      }while('\n' != err_in && '\t' != err_in && ' ' != err_in);
    }
    cout << "choice is #" << ch << endl;
    switch(ch) {
      case 1:
	cout << "input n to push:";
	cin >> n;
	if(st.Push(n)) cout << "input is  " << n << endl;
	else cout << "full\n";
	break;
      case -1:
	if (st.Pop()) cout << "Pop!\n";
	else cout << "empty!\n";
	break;
      case 2:
	if (st.Top(n))
	  cout << " top is " << n << endl;
	else 
	  cout << "stack is empty.\n";
	break;
      default:;
    }
  }
  cout << "#endl\n";
  return 0;
}

