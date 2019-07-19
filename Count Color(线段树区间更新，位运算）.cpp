#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
#define N 400005
struct node{
	int l,r,val,sum;
}p[N];

void build(int l,int r,int cur)
{
	p[cur].l=l;
	p[cur].r=r;
	if(l==r)    
		return;
	int m=(l+r)/2;
	build(l,m,2*cur);    
	build(m+1,r,2*cur+1);
}

void update(int ul,int ur,int cur,int v)
{
	if(ul==p[cur].l && ur==p[cur].r)
	{
		p[cur].sum=1;   //标记用来延迟更新
		p[cur].val=1<<(v-1);
		return;
	}
	if(p[cur].sum)    //pushdown
	{
		p[cur].sum=0;
		p[cur*2].sum=p[cur*2+1].sum=1;
		p[cur*2].val=p[cur*2+1].val=p[cur].val;
	}
	int m=(p[cur].l+p[cur].r)/2;
	if(ur<=m) update(ul,ur,2*cur,v);
	else if(ul>m)update(ul,ur,2*cur+1,v);
	else {
		update(ul,m,2*cur,v);
		update(m+1,ur,2*cur+1,v);
	}
	p[cur].val=(p[cur*2].val|p[cur*2+1].val);
	if(p[cur*2].sum && p[cur*2+1].sum && p[cur*2].val==p[cur*2+1].val)
	p[cur].sum=1;
}
int query(int ql,int qr,int cur)  //查询区间值
{
	if(ql==p[cur].l && qr==p[cur].r) return p[cur].val;
	if(p[cur].sum) return p[cur].val;
	
	int m=(p[cur].l+p[cur].r)/2;
	if(qr<=m) return query(ql,qr,2*cur);     
	else if(ql>m) return query(ql,qr,2*cur+1);
	else {
		return query(ql,m,2*cur)|query(m+1,qr,2*cur+1);
	}
}
int main()
{
	int l,t,o;
	while(scanf("%d %d %d",&l,&t,&o)!=EOF)
	{
		build(1,l,1);
		p[1].val=p[1].sum=1;
		char str;
		while(o--)
		{
			cin>>str;
			int ql,qr,add;
			
			if(str=='P')
			{
				scanf("%d %d",&ql,&qr);
				int ans=query(ql,qr,1);
				int s=0;
				for(int i=0;i<t;i++)
				{
					if(ans&(1<<i)) s++;
				}
				printf("%d\n",s);
			}
			else
			{
				scanf("%d %d %d",&ql,&qr,&add);
				update(ql,qr,1,add);
			}
		}
	}
	return 0;
}
