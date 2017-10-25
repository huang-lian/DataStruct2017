#ifndef MALL_WORK_H
#define MALL_WORK_H
#include"product.h"
class MallWork{
  public:
    MallWork(const char * work_file);

    MallWork(void);
    MallWork(const MallWork & mlwork);
    ~MallWork(void);
    MallWork & operator=(const MallWork & mlwork);

    /* 使用文件进行初始化工作内容
     * 如果文件存在,加载文件
     * 如果文件不存在,创建文件并提示添加信息
     * */
    bool Init(const char * file_name);

    void Stock(void);
    void Pick(void);
    void Search(void);
    void Update(void);
    void Stop(const char * file_name);

  private:
    struct AppNode{
      Product app;
      struct AppNode * next;
    };
    AppNode * store_;

    void Read(const char *file_name);
    // 合并opertor= 和 拷贝构造函数部分公共代码.
    void SetStore(const MallWork & mlwork);

    // 链表的操作
    void Create(const char * file_name = NULL);
    bool Insert(const Product & goods);
    bool Delete(const Product & goods);

    AppNode *SameName(const Product & goods, AppNode ** save_ppre = NULL);
    AppNode *Free(AppNode *p);
    int ShowLink(AppNode *header);

    void SeachAtName(void);
    void SeachAtBrand(void);
    void SeachAtPrice(void) const;
    void SeachAtStore(void) const;

    void Del(void);
    void Change(void);

};
#endif // MALL_WORK_H
