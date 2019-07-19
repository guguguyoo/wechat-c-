#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
int n,m,t;
ll dp[10005][20];
int a[1000005][2];
void dfs(int c,int d,int e)
{
	if(c>m) return;
	if(c==m)
	{
		a[t][0]=d;
		a[t++][1]=e;
		return;
	}
	dfs(c+1,d<<1,e<<1|1);
	dfs(c+1,d<<1|1,e<<1);
	dfs(c+2,d<<2|3,e<<2|3);
}
int main()
{
	while(cin>>n>>m && n && m)
	{
		if(m>n) swap(n,m);
		t=0;
		dfs(0,0,0);
		memset(dp,0,sizeof(dp));
		dp[(1<<m)-1][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<t;j++)
			dp[a[j][1]][i]+=dp[a[j][0]][i-1];
			
		cout<<dp[(1<<m)-1][n]<<endl;
	}
	return 0;
}
