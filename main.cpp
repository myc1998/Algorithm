//石子合并问题：
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int INF = 1 << 30;
const int N = 205;
int mins[N][N];
int maxs[N][N];//临时存储
int sum[N],a[N];//计算合，储存每个石子堆个数
int minval,maxval;//最终的最小值与最大值
int n;//石子堆个数
int getSum(int i,int j){//从第i堆开始，第j堆石子
	if (i + j > n)
		return getSum(i, n - i - 1) + getSum(0, (i + j) % n);
	else
return sum[i+j] - (i>0 ? sum[i-1]:0);
}
void Work(int a[],int n)
{
    for(int i=0;i<n;i++)
        mins[i][0] = maxs[i][0] = 0;
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            mins[i][j] = INF;
            maxs[i][j] = 0;
            for(int k=0;k<j;k++)
            {
                mins[i][j] = min(mins[i][j],mins[i][k] + mins[(i+k+1)%n][j-k-1] + getsum(i,j));
                maxs[i][j] = max(maxs[i][j],maxs[i][k] + maxs[(i+k+1)%n][j-k-1] + getsum(i,j));
            }
        }
    }
    minval = mins[0][n-1];
    maxval = maxs[0][n-1];
    /*for(int i=0;i<n;i++)
    {
        minval = min(minval,mins[i][n-1]);
        maxval = max(maxval,maxs[i][n-1]);
    }*/
}

int main()
{

    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum[0] = a[0];
        for(int i=1;i<n;i++)
            sum[i] = sum[i-1] + a[i];
        Work(a,n);
        printf("%d\n%d",minval,maxval);
    }
    return 0;
}






/*#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
stack<int> s;
int cmp1(int a,int b)
{
    return b>a;
}

int main(){
    int n;
    cin>>n;
    int a[10];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int sum[10];
    sum[0]=a[0]+a[1];
    int add=sum[0];
    for(int i=0;i<n-2;i++){
        sum[i+1]=sum[i]+a[i+2];
        add=add+sum[i+1];
    }
     cout<<add<<endl;

    for(int i=0;i<n;i++)
      s.push(a[i]);
    int b[10];
    for(int i=0;i<n;i++){
        b[i]=s.top();
        s.pop();
    }
    sum[0]=b[0]+b[1];
    int addx=sum[0];
    for(int i=0;i<n-2;i++){
        sum[i+1]=sum[i]+b[i+2];
        addx=addx+sum[i+1];
    }
    cout <<addx<<endl;
    return 0;
} */




