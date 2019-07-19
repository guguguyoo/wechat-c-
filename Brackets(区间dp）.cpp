#include <iostream>
#include <cstring>
using namespace std;
int dp[5005][5005];
string s;

int main()
{
	while(cin>>s && s[0]!='e')
	{
		int n=s.size();
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		dp[i][j]=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0,k=i;k<n;j++,k++)
			{
				if((s[j]=='(' && s[k]==')') || (s[j]=='[' && s[k]==']'))
				dp[j][k]=dp[j+1][k-1]+2;
				for(int l=j;l<k;l++)
				{
					dp[j][k]=max(dp[j][k],dp[j][l]+dp[l+1][k]);
					//cout<<dp[j][k]<<" "<<dp[j][l]<<" "<<dp[l+1][k]<<endl;
				}
			}
		}
		cout<<dp[0][n-1]<<endl;
	}
	return 0;
}
