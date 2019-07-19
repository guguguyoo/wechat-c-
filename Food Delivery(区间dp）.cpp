#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n,v,x,sum[1005];
int dp[1005][1005][2];
struct node{
	int a,b;
}p[1005];
bool cmp(node a,node b)
{
	return a.a<b.a;
}
int main()
{
	while(cin>>n>>v>>x)
	{
		for(int i=1;i<=n;i++)
		cin>>p[i].a>>p[i].b;
		n++;
		p[n].a=x;
		p[n].b=0;
		sort(p+1,p+1+n,cmp);
		sum[0]=0;
		for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+p[i].b;    //忍耐度前缀和 
		
		int tmp;
		for(int i=1;i<=n;i++)      //外卖小哥的位置编号 
			if(x==p[i].a)
			{
				tmp=i;
				break;
			}
			
		memset(dp,inf,sizeof(dp));
		dp[tmp][tmp][0]=dp[tmp][tmp][1]=0;   //起始位置不满意度为0 
		for(int i=tmp;i>0;i--)
		{
			for(int j=tmp;j<=n;j++)
			{
				dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(sum[i]+sum[n]-sum[j])*(p[j].a-p[i].a));
				dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(sum[i]+sum[n]-sum[j])*(p[i+1].a-p[i].a));
				dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(sum[i-1]+sum[n]-sum[j-1])*(p[j].a-p[j-1].a));
				dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(sum[i-1]+sum[n]-sum[j-1])*(p[j].a-p[i].a));
			}
		}
		cout<<min(dp[1][n][0],dp[1][n][1])*v<<endl;
	}
	return 0;
}
