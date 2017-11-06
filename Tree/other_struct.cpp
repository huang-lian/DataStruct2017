struct TagBtreeNode{
  Type data;
  struct TagBtreeNode * parent;
  bool tag;   // true 左,否则右 
}


