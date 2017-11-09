# `queue_stack`队列模拟栈的操作
# 问题描述
已经实现队列的操作,现在s使用队列来模拟栈的push,pop操作

# 实现思路
栈是先进后出,只在一端操作.队列先进先出,分别在两端操作.现在考虑使用两个队列来模拟栈的操作.
## 简化push,的方法
队列的一端进入,一端出,直觉上压入是容易的.如果需要出栈,显然是需要将之前的全部出队才可以出最后一个进栈的元素.可用使用另外一个队列来缓存[前边]的元素,从而实现出栈.
- push:
	- 如果都是空队列,进入s1
	- 否则,进入非空队列.
- pop:
	- 都空,无法弹出
	- 一个非空,只保留最后一个元素,其余元素都出队后进入另外一个队列.
- top:
	- 非空队列的尾元素,但是由于队列本身不提供访问队尾的方法,所以需要增加一些操作才能访问到队首.

## 简化pop的方法
现在换一种思路,假定pop操作只需要一次出队,那么该如何入队?
如果pop只需要一次操作,那么这个元素一定是最后入队的元素,显然的,这个队列只有它的存在.而后的连续pop也是如此.所以pop对应的这个队列的顺序是有序的,是按照出栈的顺序排列好了的.故,每次入栈(入队),的元素一定是进入一个空队列,之前的序列需要跟着入队到该队列后面.
- pop: 
	- 都空,无法弹出
	- 有一个非空,非空队列出队即可,
- push:
	- 都空,进入s1
	- 一个非空,则进入空队列,将非空队列的元素逐一出队入队到到刚才队列中.
- top : 非空队列的队首

# 具体实现
本文件采用的是第二种方法,这种方法访问栈顶更为容易(O(1)).
文件使用了之前的`link_queue`.继承了其限制.