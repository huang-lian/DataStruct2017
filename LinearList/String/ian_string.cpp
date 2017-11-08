#include"ian_string.h"

size_t IanString::Kmp(const IanString & ianstr) {
  // #pass
}

void IanString::SetNewNext(const IanString & ianstr,size_t *newnext) {
  // #pass
}

IanString::IanString(void) {
  // #pass
}

IanString::IanString(const char * c_str, size_t size_) {
  // #pass
}

IanString::IanString(const IanString & i_str) {
  // #pass
}

IanString::~IanString(void) {
  // #pass
}

const IanString & IanString::operator=(const IanString & ianstr) {
  // #pass
}

const IanString & IanString::MakeNull(void) {
  // #pass
}


void IanString::Insert(const IanString & ianstr, size_t index) {
  // #pass
}

void IanString::Delete(const IanString & ianstr) {
  // #pass
}

// 结尾添加一个新字符串
void IanString::Append(const IanString & ianstr) {
  // #pass
}


// 返回匹配的第一个字串的下标
size_t IanString::Index(const IanString &ianstr) {
  // #pass
}

bool IanString::IsEmpty(void)const {
  // #pass
}
// 取出m~n之间的字串,这是一个拷贝
const IanString  IanString::SubStr(size_t m, size_t n) const {
  // #pass
}


const char & IanString::operator[](size_t index) const {
  // #pass
}

char & IanString::operator[](size_t index) {
  // #pass
}


// 获得一个c风格的字符串,这也是一个拷贝串

const char *IanString::c_str(void) {
  // #pass
}

const IanString  Concat(const IanString & ianstr1,const IanString & ianstr2) {
  // #pass
}
const IanString  operator+(const IanString & ianstr1,const IanString & ianstr2){
  // #pass
}

bool operator==(const IanString & str1, const IanString & str2) {
  // #pass
}

bool operator!=(const IanString & str1, const IanString & str2) {
  // #pass
}

const std::ostream & operator<<(std::ostream & os, const IanString & ianstr) {
  // #pass
}

const std::istream & operator>>(std::ostream &is, const IanString & ianstr) {
  // #pass
}


