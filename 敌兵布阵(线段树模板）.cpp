#include <bits/stdc++.h>
using namespace std;
#define N 200005
int a[N];   //存每个工兵营的人数

struct node{
	int l,r,val;
}p[N];
void pushup(int cur)
{
	p[cur].val=p[2*cur].val+p[2*cur+1].val;   //父节点是两个子节点的和，一直往上传值，就能使根节点是所有人的个数
}
void build(int l,int r,int cur)
{
	int m=(l+r)/2;
	p[cur].val=0;
	p[cur].l=l;
	p[cur].r=r;
	if(l==r)    //如果到达叶节点就把人数赋给该节点
	{
		p[cur].val=a[l];
		return;
	}
	build(l,m,2*cur);    //如果不是叶节点，就一直递归找左右孩子，然后直到找到叶节点进行传值
	build(m+1,r,2*cur+1);
	pushup(cur);
}
void update(int id,int num,int cur)
{
	int l=p[cur].l,r=p[cur].r;
	if(l==r)      //达到叶节点就更新 
	{
		p[cur].val=p[cur].val+num;
		return;
	}
	int m=(l+r)/2;
	if(id<=m) update(id,num,2*cur);
	else update(id,num,2*cur+1);
	pushup(cur);
}
int query(int ql,int qr,int cur)  //查询区间值
{
	int l=p[cur].l,r=p[cur].r;
	if(ql<=l && qr>=r) return p[cur].val;  //如果一个树的节点所在的区间能够被所求区间完全包含（包括等于），那么就直接返回该区间值
	int m=(l+r)/2,ans=0;
	if(ql<=m) ans+=query(ql,qr,2*cur);     //如果不能完全包含，就去找他的左右孩子
	if(qr>m) ans+=query(ql,qr,2*cur+1);
	return ans;
}
int main()
{
	int t,n;
	char str[50];
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,n,1);
		int f=1;
		while(scanf("%s",str))
		{
			if(f) printf("Case %d:\n",k),f=0;
			
			if(!strcmp(str,"Query"))
			{
				int ql,qr;
				scanf("%d %d",&ql,&qr);
				printf("%d\n",query(ql,qr,1));
			}
			else if(!strcmp(str,"Add"))
			{
				int id,num;
				scanf("%d %d",&id,&num);
				update(id,num,1);
			}
			else if(!strcmp(str,"Sub"))
			{
				int id,num;
				scanf("%d %d",&id,&num);
				update(id,-num,1);
			}
			else break;
		}
	}
	return 0;
}
