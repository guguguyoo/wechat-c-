#include <bits/stdc++.h>
using namespace std;
#define N 1005
struct node{
	int id;
	int l;
	int r;
}shu[N];

int n;
int xian[N];
int zhong[N];
int pos[N];
int idx=0;
vector<int>ans;

int build(int xianl,int xianr,int zhongl,int zhongr)
{
	if(xianl>xianr || zhongl>zhongr) return -1;
	idx++;
	int now=idx;
	int root=xian[xianl];   //根节点
	int l_len=pos[root]-zhongl;  //左子树的长度 
	shu[now].id=root;    
	shu[now].l=build(xianl+1,xianl+l_len,zhongl,pos[root]-1); //左子树的先序边界，中序边界 
	shu[now].r=build(xianl+l_len+1,xianr,pos[root]+1,zhongr); //右子树的先序边界，中序边界 
	return now;
}

void post_order(int x)
{
	if(x==-1) return;
	post_order(shu[x].l);
	post_order(shu[x].r);
	ans.push_back(shu[x].id);
}
int main()
{
	while(cin>>n)
	{
		ans.clear();
		idx=0;
		memset(shu,-1,sizeof(shu));
		for(int i=1;i<=n;i++)
		cin>>xian[i];
		for(int i=1;i<=n;i++)
		{
			cin>>zhong[i];
			pos[zhong[i]]=i;
		}
		int root=build(1,n,1,n);
		post_order(root);
		for(int i=0;i<n;i++)
		if(i!=n-1) 
		cout<<ans[i]<<" ";
		else
		cout<<ans[i]<<endl;
	}
	return 0;
}
