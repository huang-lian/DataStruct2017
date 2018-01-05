#include<iostream>
#include<fstream>
#include"arr_max_heap.h"
struct Task{
  int num;
  int key;
  Task(int n = 0,int k = 0) :num(n),key(k)
  {
  };
  bool operator<(const struct Task & atask)
  {
    return key < atask.key;
  };
};
int main(void) {
  using namespace std;
  ArrMaxHeap<Task> heap;
  Task tsk;
  cout << "start#\n";
  fstream fin("task.txt");
  if(fin.is_open()) {
    while(!fin.eof()) {
      fin >> tsk.num >> tsk.key;
      heap.Insert(tsk);
    }
  }
  fin.close();
  while(heap.Delete(tsk)) {
    cout << tsk.num <<"\t" << tsk.key << endl;
  }
  cout << "#endl\n";
  return 0;
}

