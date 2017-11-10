// C++ file
/* 线性表的数组实现, 标记了last
 * author:huang_lian@126.com
 * date:2017年10月19日 星期四
 **/
#ifndef ARRAY_LIST
#define ARRAY_LIST
#define MAX_SIZE_ARRLIST 100
template<class Type>
class ArrayList{
  public:
    explicit ArrayList(size_t size = MAX_SIZE_ARRLIST);
    ArrayList(const Type * arr, size_t n, size_t size = MAX_SIZE_ARRLIST);
    ~ArrayList(void);

    bool Insert(const Type & data, size_t pos);
    bool Delete(size_t pos);

    size_t Locate(const Type & data) const;
    // 如果元素不存在，返回线性表大小


    const Type & operator[](size_t pos) const;
    Type & operator[](size_t pos);
    // 重载了下标访问的方式,所以不再实现 以下几个功能函数
    // const Type & End(void) const {return arr_[size_ -1];}; 
    // const Type & Previous(size_t pos) const  {return arr_[pos - 1];};
    // const Type & Next(size_t pos) const {return arr_[pos + 1];};
    // const Type & Retrieve(size_t pos) const {return arr_[pos];};

    size_t size(void) const {return last_;};

  private:
    size_t last_; // 始终等于长度（指向要存的下一个位置)
    size_t size_;
    Type * arr_;
};

template<class Type>
ArrayList<Type>::ArrayList(size_t size) : last_(0),size_(size) {
  arr_ = new Type[size_];
}

template<class Type>
ArrayList<Type>::ArrayList(const Type * arr, size_t n, size_t size) : last_(n) {
  size_ = size > n ? size : n;
  arr_ = new Type[size_];
  for(int i = 0; i < last_; i++) {
    arr_[i] = arr[i];
  }
}

template<class Type>
ArrayList<Type>::~ArrayList(void) {
  delete [] arr_;
}

template<class Type>
bool ArrayList<Type>::Insert(const Type & data, size_t pos) {
  if (pos >= size_) return false;
  for(size_t i = last_; i > pos; i--) {
    arr_[i] = arr_[i-1];
  }
  last_ ++;
  arr_[pos] = data;
  return true;
}

template<class Type>
bool ArrayList<Type>::Delete(size_t pos) {
  if (pos >= last_) return false;
  for(int i = pos; i< last_ -1 ; i ++) {
    arr_[i] = arr_[i + 1];
  }
  last_ --;
  return true;
}

template<class Type>
size_t ArrayList<Type>::Locate(const Type & data ) const {
  for(int i = 0; i < last_; i++) {
    if (data == arr_[i])
      return i;
  }
  return size_;
}

template<class Type>
const Type & ArrayList<Type>::operator[](size_t pos) const {
  return arr_[pos];
}

template<class Type>
Type & ArrayList<Type>::operator[](size_t pos) {
  return arr_[pos];
}
#endif // ARRAY_LIST
