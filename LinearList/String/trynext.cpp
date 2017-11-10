#include<iostr:eam>
using namespace std;
int  next(int  j,const char *p)
{
  if(j == 0) return -1;
  if(j == 1) return 0;
  if(p[k] == p[j])
    return k+1;
  return next(n-1,p);
}
int main(void)
{
  char a[8];
  for(int i=0;i<8;i++)
    cin >>a[i];
  for(int i=0;i<8;i++)
    cout <<next(i,a);
  return 0;
}
