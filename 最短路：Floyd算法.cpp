#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f
int a[105][105];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) a[i][j]=0;
			else a[i][j]=inf;
	
	for(int i=1;i<=m;i++)
	{
		int b,c,d;
		cin>>b>>c>>d;
		if(d<a[b][c])
		a[b][c]=a[c][b]=d;
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i][k]+a[k][j]<a[i][j])
				a[i][j]=a[i][k]+a[k][j];
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cout<<a[i][j]<<" ";
		if(j==n) cout<<endl;
	}
	return 0;
}
