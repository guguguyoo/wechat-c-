#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
#define N 400005
ll a[N];  

struct node{
	ll l,r,val,sum;
}p[N];
void pushup(int cur)
{
	p[cur].val=p[2*cur].val+p[2*cur+1].val;  //更新根节点 
}
void build(int l,int r,int cur)
{
	p[cur].sum=0;
	p[cur].l=l;
	p[cur].r=r;
	if(l==r)    
	{
		p[cur].val=a[l];
		return;
	}
	int m=(l+r)/2;
	build(l,m,2*cur);    
	build(m+1,r,2*cur+1);
	pushup(cur);
}
void pushdown(int cur)  //更新子节点 
{
	int m=p[cur].r-p[cur].l+1;
	if(p[cur].sum)
	{
		p[2*cur].sum+=p[cur].sum;
		p[2*cur+1].sum+=p[cur].sum;
		p[2*cur].val+=p[cur].sum*(m-(m>>1));
		p[2*cur+1].val+=p[cur].sum*(m>>1);
		p[cur].sum=0;
	}
}
void update(int ul,int ur,int cur,ll v)
{
	if(ul==p[cur].l && ur==p[cur].r)
	{
		p[cur].sum+=v;   //标记用来延迟更新
		p[cur].val+=v*(ur-ul+1);
		return;
	}
	if(p[cur].l==p[cur].r) return;
	pushdown(cur);
	int m=(p[cur].l+p[cur].r)/2;
	if(ur<=m) update(ul,ur,2*cur,v);
	else if(ul>m)update(ul,ur,2*cur+1,v);
	else {
		update(ul,m,2*cur,v);
		update(m+1,ur,2*cur+1,v);
	}
	pushup(cur);
}
ll query(int ql,int qr,int cur)  //查询区间值
{
	if(ql==p[cur].l && qr==p[cur].r) return p[cur].val;  
	pushdown(cur);
	ll m=(p[cur].l+p[cur].r)/2,ans=0;
	if(qr<=m) ans+=query(ql,qr,2*cur);     
	else if(ql>m) ans+=query(ql,qr,2*cur+1);
	else {
		ans+=query(ql,m,2*cur);
		ans+=query(m+1,qr,2*cur+1);
	}
	return ans;
}
int main()
{
	int n,q;
	while(scanf("%d %d",&n,&q)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		build(1,n,1);
		char str;
		while(q--)
		{
			cin>>str;
			int ql,qr,add;
			
			if(str=='Q')
			{
				scanf("%d %d",&ql,&qr);
				printf("%lld\n",query(ql,qr,1));
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
