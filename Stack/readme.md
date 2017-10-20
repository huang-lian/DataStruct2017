# 栈（Stack)
栈是线性表的一种特殊形式，是一种限定性数据结构，也就是在对线性表的操作加以限制后，形成的一种新的数据结构。

# 栈的定义：
是限定只在表尾进行插入和删除操作的线性表。
栈又称为 后进先出(Last In First Out ) 的线性表。简称 LIFO
![栈结构示意图](http://wx1.sinaimg.cn/mw690/006zpzJely1fkofnojklij30fl0fqaan.jpg)

# 相关术语解释
- 入栈:向栈中存入一个元素，也叫压栈
- 出栈:栈中删除最后一个存入元素，也叫弹栈
- 栈顶元素:最后一个压入栈的元素
- 栈空:栈中没有元素。此时没有栈顶元素，也无法弹出栈顶元素。
- 栈满:栈中空间用完了，无法再压入元素

# 栈的基本操作
`Type` 是使用的数据类型
```C++ code

  // 入栈，即将data的内容存入栈中。
  bool Push(const Type & data);
  // 数据成功压入栈，返回true，否则false(通常是栈满了，无法压入)。

  // 出栈，即将最后一个存入的数据从栈中删除
  bool Pop(void);
  // 成功弹出元素，返回true，否则false(栈空时false）。

  // 取得栈顶元素到data
  bool Top(const Type & data) const;
  // 获取成功返回true，否则false(栈空时false）。

  // 获得栈顶元素
  const Type & Top(void) const;
  // 返回栈顶元素，如果栈空，返回值未定义（可能是未知值，也可能因为实现不同)
  // 使用本例应当检查是否栈空

  // 判断栈是否空
  bool IsEmpty(void) const;
  // 如果栈空返回true，否则false

  // 判断栈是否满
  bool IsFull(void) const;
  // 栈满返回true，否则false。通常是在数组或者有限栈中

  // 置空栈
  void MakeNull(void);

```
