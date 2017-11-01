#ifndef IAN_STRING
#define IAN_STRING
#include<iostream>
class IanString{
  public:
    IanString(void);
    IanString(const char * c_str);
    IanString(const char * c_str, size_t size_);
    IanString(const IanString & i_str);
    ~IanString(void);
    const IanString &operator=(const IanString & ianstr);

    const IanString &MakeNull(void);

    // 在指定位置插入
    void Insert(const IanString & ianstr, size_t index);

    // 删除指定串,默认匹配的第一个
    void Delete(const IanString & ianstr);

    // 结尾添加一个新字符串
    void Append(const IanString & ianstr);

    // 返回匹配的第一个字串的下标
    size_t Index(const IanString &ianstr);
    bool IsEmpty(void)const;
    size_t size(void) const {return size_;};

    // 取出m~n之间的字串,这是一个拷贝
    const IanString  SubStr(size_t m, size_t n) const;

    // 获得一个c风格的字符串,这也是一个拷贝串
    const char *c_str(void);

    const char & operator[](size_t index) const;
    char & operator[](size_t index);

    friend const IanString  Concat(const IanString & ianstr1,const IanString & ianstr2);
    friend const IanString  operator+(const IanString & ianstr1,const IanString & ianstr2);

    friend bool operator==(const IanString & str1, const IanString & str2) ;
    friend bool operator!=(const IanString & str1, const IanString & str2);

    friend const std::ostream & operator<<(std::ostream & os, const IanString & ianstr);

    friend const std::istream & operator>>(std::ostream &is, const IanString & ianstr);
  private:
    struct IanStrNode{
      char data[4];
      struct IanStrNode *next;
    };
    struct IanStrNode * header_;
    size_t size_;


    size_t Kmp(const IanString & ianstr);
    void SetNewNext(const IanString & ianstr,size_t *newnext);
    struct IanStrNode * subianstr_;
    char *c_str_;

    // 为了加强单链表访问速度,保留前一次的访问值
    struct IanStrNode * preview;
    size_t  pre_index;

};
#endif //IAN_STRING
