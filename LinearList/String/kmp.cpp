// 2017年10月26日20:42:16
// 字符匹配算法-KMP算法理解
// 
// 约定
// T:主串,长的那个,寻找匹配结果的字符串
// P:模式串,短的那个,需要匹配的字符串
// i:主串下标
// j:模式串下标
// 匹配:P[i]==T[j]
// 失配:P[i]!=T[j]
// 尝试匹配:P[i]==T[j]?
// P[x1,x2]:表示P的下标x1到x2之间的一个字符片段
// next[]:是一个数组,是一个函数,next[j] 表示模式串的第j个字符失配
// 	P中该和T比较的字符下标(新的j);
//
// 参考:1.  http://www.cnblogs.com/yjiyjige/p/3263858.html

void SetNext(const char *P,size_t & next[], size_t n);
{
  size_t j = 0;   // next[j]函数(数组)的因变量
  size_t k = -1;  // 索引为j的位置对应的回溯位置
  next[0] = -1;   // 定义j==0 时,回溯位置是-1,表示再也无法回溯了
                  // 当 j==0 时P与T失配,
		  // 只能是主串P的下标i++ 再次和P[0]尝试匹配
		  //
                  // 在kmp算法过程中,如果出现这样的情况
		  // 即T[i]和第0个字符P[0]失配
		  // 主串索引i++,模式串索引j++
		  // 自然就过渡到了新的T[i] 与P[0]比较的目的

  // 对于next[j],令next[j] = k(k>=0) 需要
  // 需要寻找一个k值,令P[0,k] = P[j-k-1,j-1]
  // 当j=0时,不存在一个这样的值,以-1表示这个不存在的值.即next[0]=k=-1
  // 当j=1时,如果P[0,k] ==P[j-k-1,j-1] ==> k = 0  即next[1] = k = 0
  // 有next[1] = next[0]+1;
  // 假设,P[0,k] ==P[j-k,j-1],有next[j]=next[j-1] +1
  // 当j=j+1,立刻有next[j+1] = next[j+1-1]+1=next[j]+1,成立.
  // 于是可以递归求出next[]
  // 如果,P[0,k-1]==P[j-k,j-1],P[k]!=P[j],令next[j] = next[j-1]  

  while(j < n) {
    if (-1 ==k || P[j] == P[k]) {
      // if(w[j] ==w[k]),如果j从1开始是否可以这样写?
      // 1.
      // 2.当P[j]==P[k],始终是有next[j+1] = next[j]+1
      // 证明: 
      //    j==0,k==-1;j==1,k==0,以后j>1
      //    P[j] 之前,P[j-1]时已经有P[0,k-1] == P[j-k,j-1] // next[j]==k
      //    现在有P[j]=P[k],即可得到P[0,k-1] + P[k] == P[j-k,j-1] + P[j]
      //    即有P[0,k] == P[j-k,j],有next[j+1]==k+1==next[j]+1
      //
      //
      j++;
     k++;
     if(P[i]!=P[j])
      next[j] = k;
     else
       next[j] = next[k];

    } else {
      k = next[k];
    }
  }
}
size_t Kmp(const char * T,const char * P,size_t m, size_t n)
{
  if (m < n || n == 0)
    return -1;
  size_t i = 0;
  size_t j = 0;
  size_t *next = new char [n];
  SetNext(P,next,n);
  while(i < m)
  {
    if (-1 == j || T[i] == P[i]) {
      i++;
      j++;

    } else  {
      j = next[j];
    }
    if (j > n) return i - m + 1; 
  }
  return -1;
} // Kmp
