#include <bits/stdc++.h>
using namespace std;
bool a[505][505];
int vis[505];
int boy[505];
int k,m,n;

bool find(int x)
{
	for(int i=1;i<=n;i++)    //扫描每个汉子 
	{
		if(a[x][i]==true && vis[i]==0)//如果有暧昧并且没记录过 
		{
			vis[i]=1;
			if(boy[i]==0 || find(boy[i]))   //如果还没人要或者能腾出位置就ok 
			{
				boy[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int s;
	while(cin>>k && k)
	{
		memset(boy,0,sizeof(boy));
		memset(a,false,sizeof(a));
		s=0;
		cin>>m>>n;
		for(int i=1;i<=k;i++)
		{
			int b,c;
			cin>>b>>c;
			a[b][c]=true;     //存图 
		}
		for(int i=1;i<=m;i++)
		{
			memset(vis,0,sizeof(vis));
			if(find(i)) s++;
		}
		cout<<s<<endl;
	}
	return 0;
}
