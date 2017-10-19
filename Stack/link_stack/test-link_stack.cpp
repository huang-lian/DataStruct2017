#include<iostream>
#include"link_stack.h"

int main(void) {
  using namespace std;
  LinkStack<int> st;
  cout << "start#\n";

  int n;
  int ch = 1;
  while(0 != ch) {
    cout << "\t0.exit\t1.Push\t-1.Pop\t2.Top\n";
      cin >> ch 
    switch(ch) {
      case 1:
	cout << "input n to push:";
	cin >> n;
	if(st.Push(n)) cout << "Push!\n";
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

