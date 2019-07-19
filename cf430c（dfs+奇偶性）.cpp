#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,ans;
vector <int> vec[N];
int a[N],b[N],vis[N];
void dfs(int u,int v,int c,int d)
{
	int f=0;
	if(c%2==1)
	f=1;
	if(a[u]^f!=b[u])
	{
		ans++;
		vis[u]=1;
		c++;
	}
	for(int i=0;i<vec[u].size();i++)
	{
		int p=vec[u][i];
		if(p==v) continue;
		dfs(p,u,d,c);
	}
}
int main()
{
	cin>>n;
	int x,y;
	ans=0;
	for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
	
	for(int i=1;i<=n;i++)
	if(vis[i])
	cout<<i<<endl;
}
