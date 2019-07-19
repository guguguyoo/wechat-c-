#include <bits/stdc++.h>
using namespace std;
#define N 100005
vector <int> vec[N];//��¼ͼ 
int col[N];//��¼��ɫΪ1��-1 

bool dfs(int v,int u)
{
	col[v]=u;
	for(int i=0;i<vec[v].size();i++)
	{
		if(col[vec[v][i]]==u) return false;   //�����ͨ������Ϳ��uɫ 
		if(col[vec[v][i]]==0) 
		{
			if(dfs(vec[v][i],-u)==false)
			return false;
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	int t,n,m,x,y,s;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>m>>s;
		memset(col,0,sizeof(col));
		memset(vec,0,sizeof(vec));
		for(int j=0;j<m;j++)
		{
			cin>>x>>y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		cout<<"Case "<<k<<": ";
		if(dfs(s,1)) cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}
	return 0;
}
