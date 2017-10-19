#include<iostream>
#include"share_stack.h"

int main(void) {
  using namespace std;
  ShareStack<int> st[3];
  cout << "start#\n";
  int n;
  int ch = 1;
  int i = 0;
  while(0 != ch) {
    cout << "choice Stack i (i = 0,1,2)\n:";
    cin >> i;
    if (i<0||i >2) continue;

    cout << "Now ,in Stack " << i << endl;
    st[i].ShowStack();

    cout << "\t0.exit\t1.Push\t-1.Pop\t2.Top\n";
    cin >> ch ;
    switch(ch) {
      case 1:
	cout << "input n to push:";
	cin >> n;
       	if(st[i].Push(n)) cout << "Push!\n";
	else cout << "full\n";
	break;
      case -1:
	if (st[i].Pop()) cout << "Pop!\n";
	else cout << "empty!\n";
	break;
      case 2:
	if (st[i].Top(n))
	  cout << " top is " << n << endl;
	else 
	  cout << "stack is empty.\n";
	break;
      default:;
    }
    cout << "Now ,in Stack " << i << endl;
    st[i].ShowStack();
  }

  cout << "+++++++++++++++++\n";
  for(int j = 0; j < 3;j++) {
    cout << "Now ,in Stack " << j << endl;
    st[j].ShowStack();
  }
  cout << "#endl\n";
  return 0;
}

