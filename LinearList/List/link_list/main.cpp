#include<iostream>
#include"link_list.h"

void display(LinkList<int> & arr) {
  LinkList<int>::Postion p = arr.First();
  int cnt = 0;
  std::cout << "First <------->End\n";
  for(; NULL != p; p = arr.Next(p)) {
    std::cout << arr.Retrieve(p)<< "\t";
    cnt ++;
  }
  std::cout<< "\ncount : " << cnt  << std::endl;
}
int main(void) {
  using namespace std;
  LinkList<int> arr;
  LinkList<int>::Postion p;
  int ch = 1;
  int n;
  while(0 != ch) {
    display(arr);
    cout << "0.Exit\t1.Append\t 2.Insert\t3.Delete\n";
    cin >> ch;
    switch(ch) {
      case 1:
	cout << "InPut a Num :";
	cin >> n;
	arr.Append(n);
	cout << "Append " << n << endl;
	break;
      case 2:
	cout << "insert n @ No.x Input n,x (x from j to Count)\n";
	cin >> n >> ch;
	cout << "n = " << n << "\tx = " << ch << endl;
	for(p = arr.First(); NULL != p; p = arr.Next(p))
	{
	  ch--;
	  if(0 == ch) {
	    arr.Insert(n,p);
	    cout << "\nInsert " << n << endl;
	  }
	}
	if(ch > 0)cout << "Too big x\n";
	ch = 1;
	break;

      case 3:
	cout << "Delete @ No.x Input (x from 1 to Count)";
	cin >> n ;
	cout << "x = " << n << endl;
	for(p = arr.First(); NULL != p; p = arr.Next(p))
	{
	  n--;
	  if(0 == n) {
	    arr.Delete(p);
	    cout << "\n Delete " << n << endl;
	  }
	}
	if(ch > 0)cout << "Too big x\n";
	break;
    }
    }
    return 0;
  }
