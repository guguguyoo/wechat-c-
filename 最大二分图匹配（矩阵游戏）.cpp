#include <bits/stdc++.h>
using namespace std;
bool a[205][205];
int vis[205];
int hei[205];
int n;

bool find(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[x][i]==true && vis[i]==0)
		{
			vis[i]=1;
			if(hei[i]==0 || find(hei[i]))
			{
				hei[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int s,t;
	cin>>t;
	while(t--)
	{
		memset(hei,0,sizeof(hei));
		memset(a,false,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int b;
				cin>>b;
				if(b==1) a[i][j]=true;
				else
				a[i][j]=false;
			}
		}
		s=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(find(i)) s++;
		}
		if(s==n) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
