#include<iostream>
#include"arr_max_heap.h"
using namespace std;
int GetInt(void)
{ 
  using std::cin;
  int n;
  char err_in;
  while(!(cin >> n))

    {
      cin.clear();
      do{
	cin.get(err_in);
      }while('\n' != err_in && '\t' != err_in && ' ' != err_in);
    }
  return n;
}
int GetInt(int & n)
{
  n = GetInt();
  return n;
}
void Show(ArrMaxHeap<int> p)
{
  cout << "root<----->leaf\n";
  if(p.IsEmpty())
    cout << "NULL";
  size_t cnt= 1;
  while(!p.IsEmpty()) {
    cout<< p.Max() << ((cnt%5==0)?"\n":"\t");
    cnt++;
    p.Delete();
  }
  cout << endl;
}
int main(void) {
  ArrMaxHeap<int> st;
  int n;
  int ch = 1;
  cout << "start#\n";
  while(0 != ch) {
    Show(st);
    cout << "\t0.exit\t1.Insert\t-1.Delete\t2.Max\n";
    cout << "choice is #" << ch << endl;
    switch(GetInt(ch)) {
      case 1:
	cout << "input n to Insert:";
	n = GetInt();
	if(st.Insert(n)) cout << "Insert\t" << n << endl;
	else cout << "IsFull\n";
	break;
      case -1:
	if (st.Delete(n)) cout << "Delete! \t" << n << endl;
	else cout << "Ismpty!\n";
	break;
      case 2:
	if (st.Max(n))
	  cout << "Max is\t" << n << endl;
	else 
	  cout << "IsEmpty.\n";
	break;
      default:;
    }
  }
  cout << "#endl\n";
  return 0;
}

