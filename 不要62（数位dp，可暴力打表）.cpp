#include <bits/stdc++.h>
using namespace std;
int a[20];
int dp[20][2];
int dfs(int pos,bool c/*前导零*/,bool limit/*数位上界变量*/)
{
	if(pos==-1) return 1;
	if(limit==0 && dp[pos][c]!=-1) return dp[pos][c];
	int End=limit?a[pos]:9,ans=0;
	for(int i=0;i<=End;i++)
		if(i!=4 && !(c && i==2))
		ans+=dfs(pos-1,i==6,limit && i==End);
	
	if(limit==0)
	dp[pos][c]=ans;
	return ans;
}
int solve(int x)
{
	int pos=0;
	while(x)//数位分解 
	{
		a[pos++]=x%10;
		x=x/10;
	}
	return dfs(pos-1,0,1);
}
int main()
{
	int n,m;
	memset(dp,-1,sizeof(dp));
	while(cin>>n>>m && n && m)
	{
		cout<<solve(m)-solve(n-1)<<endl;
	}
	return 0;
}
