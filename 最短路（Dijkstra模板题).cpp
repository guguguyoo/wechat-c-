#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int a[1005][1005],s[1005],vis[1005];
int n,m,sta,t;

void dij(int x)
{
	for(int i=1;i<=n;i++)//��ʼ��ÿ���㵽ָ��������·��
	{
		s[i]=a[i][x];
	}
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	for(int i=1;i<n;i++)//����ѡ�����·���ĵ㣬�ܹ�n-1��
	{
		int mi,mi_id;
		mi=inf;
		mi_id=i;
		for(int j=1;j<=n;j++)//�ҳ����·���ĵ��Լ��±�
		{
			if(mi>s[j] && vis[j]==0)
			{
				mi=s[j];
				mi_id=j;
			}
		}
		vis[mi_id]=1;
		for(int k=1;k<=n;k++)//����һ��ÿ���㵽ָ�������̾���
		if(s[k]>s[mi_id]+a[mi_id][k] && vis[k]==0)
		s[k]=s[mi_id]+a[mi_id][k];
	}
}
int main()
{
	cin>>n>>m>>sta>>t;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	a[i][j]=inf;
	
	for(int i=1;i<=m;i++)
	{
		int b,c,d;
		cin>>b>>c>>d;
		if(d<a[b][c])
		a[b][c]=a[c][b]=d;
	}
	dij(sta);
	//������������·������s��
	cout<<s[t]<<endl;
}
