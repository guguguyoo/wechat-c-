#include <bits/stdc++.h>
using namespace std;
#define N 800005
int a[N];

struct node{
	int l,r,val;
}p[N];
void pushup(int cur)
{
	p[cur].val=max(p[2*cur].val,p[2*cur+1].val);   //���ڵ��������ӽڵ�ĺͣ�һֱ���ϴ�ֵ������ʹ���ڵ��������˵ĸ���
}
void build(int l,int r,int cur)
{
	int m=(l+r)/2;
	p[cur].val=0;
	p[cur].l=l;
	p[cur].r=r;
	if(l==r)    //�������Ҷ�ڵ�Ͱ����������ýڵ�
	{
		p[cur].val=a[l];
		return;
	}
	build(l,m,2*cur);    //�������Ҷ�ڵ㣬��һֱ�ݹ������Һ��ӣ�Ȼ��ֱ���ҵ�Ҷ�ڵ���д�ֵ
	build(m+1,r,2*cur+1);
	pushup(cur);
}
void update(int id,int num,int cur)
{
	int l=p[cur].l,r=p[cur].r;
	if(l==r)      //�ﵽҶ�ڵ�͸��� 
	{
		p[cur].val=num;
		return;
	}
	int m=(l+r)/2;
	if(id<=m) update(id,num,2*cur);
	else update(id,num,2*cur+1);
	pushup(cur);
}
int query(int ql,int qr,int cur)  //��ѯ����ֵ
{
	int l=p[cur].l,r=p[cur].r;
	if(ql<=l && qr>=r) return p[cur].val;  
	int m=(l+r)/2,ans=0;
	if(ql<=m) ans=max(ans,query(ql,qr,2*cur));     
	if(qr>m) ans=max(ans,query(ql,qr,2*cur+1));
	return ans;
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,n,1);
		char str;
		int ql,qr;
		while(m--)
		{
			getchar();
			scanf("%c %d %d",&str,&ql,&qr);
			if(str=='Q')
				printf("%d\n",query(ql,qr,1));
			else
				update(ql,qr,1);
		}
	}
	return 0;
}
