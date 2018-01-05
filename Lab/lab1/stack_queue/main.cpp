#include<iostream>
#include<string>
#include"stack_queue.h"
using namespace std;
void Show(StackQueue<string> p)
{
  cout << "队首<----->队尾\n";
  if(p.IsEmpty())
    cout << "NULL";
  while(!p.IsEmpty()) {
    cout << p.Front() << "\t";
    p.DeQueue();
  }
  cout << endl;
}
int main(void) {
  StackQueue<string> st;
  string n;
  int ch = 1;
  char err_in;
  cout << "start#\n";
  while(0 != ch) {
    Show(st);
    cout << "\t0.exit\t1.EnQueue\t-1.DeQueue\t2.Front\n";
    while(!(cin >> ch))
    {
      cin.clear();
      do{
	cin.get(err_in);
      }while('\n' != err_in && '\t' != err_in && ' ' != err_in);
    }
    cout << "choice #" << ch << endl;
    switch(ch) {
      case 1:
	cout << "input n to enqueue:";
	cin >> n;
	cout << "input is " << n << endl;
	if(st.EnQueue(n)) cout <<endl<< n << " EnQueue!\n";
	else cout << "full\n";
	break;
      case -1:
	st.Front(n);
	if (st.DeQueue()) cout << n << " DeQueue!\n";
	else cout << "empty!\n";
	break;
      case 2:
	if (st.Front(n))
	  cout << " front is " << n << endl;
	else 
	  cout << "queue is empty.\n";
	break;
      default:;
    }
  }
  cout << "#endl\n";
  return 0;
}

