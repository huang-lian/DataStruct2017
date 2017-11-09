struct TagBtreeNode{
  // DS2017_3-46
  Type data;
  struct TagBtreeNode * parent;
  bool tag;   // true 左,否则右 
}


