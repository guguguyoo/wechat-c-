#include <iostream>
using namespace std;
#define N 150005
int n,a[N];
int dp[N][2];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]);
		dp[i][1]=max(dp[i-1][1],dp[i-1][0]-a[i]);
		//cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<max(dp[n][0],dp[n][1])<<endl;
	return 0;
}
