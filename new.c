#include <stdio.h>

int num=0;
int ans[20], answer[20];
int check(int a,int n)
{
  for(int i=0; i<n; i++)
  {
    if(ans[i]==a)  return 0;
  }
  return 1;
}

void dfs(int n)
{
  if(n>=num)
  {
    for (int i=0; i<num; i++)
    {
      printf("%d",answer[ans[i]-1]);
    }
    printf(" ");
    return;
  }
  for(int i=1; i<=num; i++)
  {
    if(check(i,n))
    {
      ans[n]=i;
      dfs(n+1);
      ans[n]=0;
    }
  }
  return;
}

int main()
{
    freopen("in.txt","r",stdin);
    int tmp;
    while(scanf("%d",&tmp)!=EOF)
    {
        answer[num]=tmp;
        num++;
    }
    for(int i=1;i<=num;i++)
    {
        ans[i]=i;
    }
    dfs(0);
    return 0;
}
