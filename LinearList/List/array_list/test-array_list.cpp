#include<iostream>
#include"array_list-1.h"

int main(void) {
  using namespace std;
  int arr[4] = { 1, 3, 5, 22};
  ArrayList<int> arr2(arr, 4);
  for(int i = 0; i < arr2.size(); i++)
    cout << arr2[i]<< "\t";
  cout << endl;
  arr2.Delete(1);
  for(int i = 0; i < arr2.size(); i++)
    cout << arr2[i]<< "\t";
  cout << endl;
  arr2.Insert(2,3);
  for(int i = 0; i < arr2.size(); i++)
    cout << arr2[i]<< "\t";
  cout << endl;

  return 0;
}
