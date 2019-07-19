#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[205][205];
int a[205],b[205];

int main()
{
	int t,n;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		cin>>b[i];
		
		b[0]=b[n+1]=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		dp[i][i]=a[i]+b[i-1]+b[i+1];
		
		for(int i=n-1;i>0;i--)
		{
			for(int k=i+1;k<=n;k++)
			{
				dp[i][k]=min(dp[i+1][k]+b[i-1]+b[k+1]+a[i],dp[i][k-1]+b[i-1]+b[k+1]+a[k]);
				for(int l=i+1;l<=k-1;l++)
				{
					dp[i][k]=min(dp[i][k],a[l]+b[i-1]+b[k+1]+dp[i][l-1]+dp[l+1][k]);
				}
			}
		}
		cout<<"Case #"<<j<<": "<<dp[1][n]<<endl;
	}
}
