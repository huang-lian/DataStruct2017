#include<iostream>
#include"link_queue.h"

int main(void) {
  using namespace std;
  LinkQueue<int> st;
  cout << "start#\n";
  int n;
  int ch = 1;
  while(0 != ch) {
    cout << "\t0.exit\t1.EnQueue\t-1.DeQueue\t2.Front\n";
    cin >> ch ;
    cout << "choice #" << ch << endl;
      switch(ch) {
      case 1:
	cout << "input n to enqueue:";
	cin >> n;
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

