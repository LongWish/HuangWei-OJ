#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<climits> 
using namespace std; 
int f[10005],far[10005],a[10005],flag[10005],p,s,t,n; 
int main() 
{ 
    scanf("%d",&p); 
    scanf("%d%d%d",&s,&t,&n); 
    if(s==t) //特殊情况判断
    { 
        int cont=0,qaq; 
        for(int i=1;i<=n;++i)scanf("%d",&qaq),cont+=((qaq%s)==0); 
        printf("%d\n",cont);return 0; 
    } 
    for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
    sort(a+1,a+n+1);a[0]=0;f[0]=0; 
    far[n+1]=min(p-a[n],100);p=0; //计算终点与最后一个点的距离
    for(int i=1;i<=n;i++)far[i]=min(a[i]-a[i-1],90),p+=far[i],flag[p]=1; //缩短路径，存储缩短后的终点距离并标记石头位置
    p+=far[n+1]; 
    for(int i=1;i<=p+9;i++) 
    { 
        f[i]=INT_MAX-1; 
        for(int j=s;j<=t;j++)if(i>=j)f[i]=min(f[i],f[i-j]+flag[i]); 
    } 
    int minn=INT_MAX-1; 
    for(int i=p;i<=p+9;i++) //因为青蛙可以跳出边界且t<=10因此再终点后p-p+9中取最小值
    minn=min(minn,f[i]); 
    printf("%d\n",minn); 
    for(int i = 1; i <= p+t; i++){
        if(flag[i] == 1)    printf("%d ", i);
    }
    printf("%d ", p);
} 
