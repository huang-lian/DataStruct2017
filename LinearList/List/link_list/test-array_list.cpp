#include<iostream>
#include"link_list.h"

void display(LinkList<int> & arr) {
  std::cout << "Size: " << arr.size() << std::endl;
  for(int i = 0; i < arr.size(); i++)
    std::cout <<arr[i] << "\t";
  std::cout << "\n";
}
int main(void) {
  using namespace std;
  int arr[4] = { 1, 3, 5, 22};
  LinkList<int> arr2;
  cout << "#start\n";
  for(int i = 0; i < 4; i++)
    arr2.Append(arr[i]);
  display(arr2);
  arr2.Delete(1);
  display(arr2);
  arr2.Insert(2,3);
  LinkList<int> arr3;
  arr3 = arr2;
  display(arr3);

  return 0;
}
