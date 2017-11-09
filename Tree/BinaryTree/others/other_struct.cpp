struct TagBtreeNode{
  // DS2017_3-46
  Type data;
  struct TagBtreeNode * parent;
  bool tag;   // true 左,否则右 
}

struct BtreeNode{
  // DS2017_3-46
  Type data;
  struct BtreeNode * parent;
  struct BtreeNode * rc;
  struct BtreeNode * lc;
  bool tag;   // true 左,否则右 
}


