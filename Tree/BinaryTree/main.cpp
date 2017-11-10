#include<iostream>
//#include"binary_tree.h"
#include"btree.h"

int main(void) {
  BinaryTree<char> bt;
  bt.Create();
  bt.PreOrder();
  bt.InOrder();
  bt.PostOrder();
  bt.LeverOrder();
  bt.LeverNumAndRight();
  bt.Count();
  bt.Height();
  BinaryTree<char> bt2 = bt;
  bt.Exchange();
  bt2.LeverOrder();
  return 0;
}
