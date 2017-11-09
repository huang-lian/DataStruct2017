#include<iostream>
#include"binary_tree.h"

int main(void) {
  BinaryTree bt;
  bt.Create();
  bt.PreOrder();
  bt.InOrder();
  bt.PostOrder();
  bt.LeverOrder();
  bt.Count();
  bt.Height();
  bt.Exchange();
  return 0;
}
