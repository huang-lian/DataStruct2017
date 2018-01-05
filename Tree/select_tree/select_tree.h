/*
 * huang_lian@126.com
 * 选择树
 * */
#ifndef SELECT_TREE_H
#define SELECT_TREE_H
// 一棵选择二叉树
class SelectTree{
  public:
    // 依据n个归并段,建立二叉选择树
    // arr存放各个归并段的首地址.m是归并段的长度.
    SelectTree(Type *arr[], size_t n, size_t m);
    SelectTree(const SelectTree &slcttr);
    ~SelectTree(void);
    const SelectTree &operator=(const SelectTree &slcttr);
    void Create(void);
  private:
    
    // 记录归并段的数量;
    size_t num_;

    // 记录归并段的长度
    size_t length_;

    // 记录访问到归并段的索引位置.
    size_t *Pos_;
};
#endif // SELECT_TREE_H
