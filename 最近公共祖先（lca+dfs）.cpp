#include <bits/stdc++.h>
using namespace std;
#define N 50000
int t,n;
struct node{
	int u,v;
	node(int a,int b)
	{
		u=a;
		v=b;
	}
};
vector <node> vec[N];
int dis[N],p[N][30],deep[N];

void dfs(int uu,int f)
{
	p[uu][0]=f;   //父节点 
	int num=vec[uu].size();
	for(int i=0;i<num;i++)
	{
		int w=vec[uu][i].u;
		if(w!=f)
		{
			deep[w]=deep[uu]+1;
			dis[w]=dis[uu]+vec[uu][i].v;
			dfs(w,uu);
		}
	}
}
void init()
{
	for(int j=1;j<=20;j++)
	for(int i=1;i<=n;i++)
	p[i][j]=p[p[i][j-1]][j-1];
}
int lca(int a,int b)
{
	int i,j;
	if(deep[a]<deep[b]) swap(a,b);
	for(int i=20;i>=0;i--)//先让a跳2^20次（最大）。假设我们发现深度比b小了，这就表示跳过了，我们再试试跳2^19次，如果还过了，那就再变小。
	{
		if((deep[a]-(1<<i))>=deep[b]) a=p[a][i];
	}
	if(a==b) return a;//当b是a的祖先时，跳到同一深度时a==b已经是LCA了，此时就不用再往上跳了。
	for(j=20;j>=0;j--)//我们还是让两个点跳2^20次，如果发现跳完后相同了，就可以确定跳到祖先了，但不一定是最近的，接着，试试跳2^19次，如果还是相同，那就再变小，如果不相同，那就跳
	{
		if(p[a][j]!=p[b][j])
		{
			a=p[a][j];
			b=p[b][j];
		}
	}
	return p[a][0];
}
int main()
{
	cin>>t;
	while(t--)
	{
		int m,a,b,c;
		cin>>n>>m;
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<=n-1;i++)
		{
			cin>>a>>b>>c;
			vec[a].push_back(node(b,c));
			vec[b].push_back(node(a,c));
		}
		dfs(1,1);
		init();
		for(int i=1;i<=m;i++)
		{
			int d,e;
			cin>>d>>e;
			cout<<dis[d]+dis[e]-2*dis[lca(d,e)]<<endl;
		}
	}
	return 0;
}
