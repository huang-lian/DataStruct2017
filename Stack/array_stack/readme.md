# `array_stack.h` 栈的数组实现
# 实现细节
见文件`array_stack.h`本身
# 使用`array_stack.h`
- 下载`array_stack.h`到你需要的位置
- 包含本文件，即在你的`*.cpp`文件开始写下
  ```C++ code
  // C++ file
#include"array_stack.h"
  ```
## 示例 
  见`test-array_stack.cpp`
## 限制
- 确保你使用的类型支持`operator=`，即相互之间的赋值。`c_str`C风格的字符数组本实现不支持，你可以使用 `std::string` 类型的代替。
- 默认栈的最大值是`MAX_SIZE_ARRST` 100, 如果你需要更大的空间请在创建的时候指定栈最大空间，或者修改宏定义`MAX_SIZE_ARRST`（但是不建议这样做）。例如你可以这样做(推荐）：
  ```C++ code ...
  // other code ..
  ArrayStack<int>st(120);
  // other code ...
  ```
- 使用`const Type & Top(void) const ` 前你应当确保栈不是空的，否则返回值不能被确定。你可以这样确保正常使用:
  ```C++ code
  // other code ...
  ArrayStack<int> st;
  int top;
  if(!st.IsEmpty())
    top = st.Top()
  // other code ...
  ```
