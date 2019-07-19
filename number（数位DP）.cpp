#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[20];
int dp[20][20][3];

ll dfs(int pos,int mod,int have,bool limit)
{
	int mod1,have1;
	if(pos==-1) return mod==0&&have==2;
	if(limit==0 && dp[pos][mod][have]!=-1) return dp[pos][mod][have];
	int End=limit?a[pos]:9;
	ll cnt=0,i;
	for(i=0;i<=End;i++)
	{
		mod1=(mod*10+i)%13;
		have1=have;
		if(have==0 && i==1) have1=1;
		if(have==1 && i!=1) have1=0;
		if(have==1 && i==3) have1=2;
		cnt+=dfs(pos-1,mod1,have1,limit&&i==a[pos]);
	}
	if(limit==0)
	dp[pos][mod][have]=cnt;
	return cnt;
}
ll solve(ll x)
{
	int pos=0;
	while(x)
	{
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,0,true);
}
int main()
{
	ll n;
	memset(dp,-1,sizeof(dp));
	while(cin>>n)
	{
		cout<<solve(n)<<endl;
	}
	return 0;
} 
