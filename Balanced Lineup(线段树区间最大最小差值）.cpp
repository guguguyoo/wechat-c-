#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define N 200005
int a[N];  

struct node{
	int l,r,mi,ma;
}p[N];
void pushup(int cur)
{
	p[cur].mi=min(p[2*cur].mi,p[2*cur+1].mi);
	p[cur].ma=max(p[2*cur].ma,p[2*cur+1].ma);  
}
void build(int l,int r,int cur)
{
	p[cur].l=l;
	p[cur].r=r;
	if(l==r)    
	{
		p[cur].mi=p[cur].ma=a[l];
		return;
	}
	int m=(l+r)/2;
	build(l,m,2*cur);    
	build(m+1,r,2*cur+1);
	pushup(cur);
}
int querymi(int ql,int qr,int cur)  //查询区间值
{
	int l=p[cur].l,r=p[cur].r;
	if(ql<=l && qr>=r) return p[cur].mi;  
	int m=(l+r)/2,ans=inf;
	if(ql<=m) ans=min(ans,querymi(ql,qr,2*cur));     
	if(qr>m) ans=min(ans,querymi(ql,qr,2*cur+1));
	return ans;
}
int queryma(int ql,int qr,int cur)  //查询区间值
{
	int l=p[cur].l,r=p[cur].r;
	if(ql<=l && qr>=r) return p[cur].ma;  
	int m=(l+r)/2,ans=0;
	if(ql<=m) ans=max(ans,queryma(ql,qr,2*cur));     
	if(qr>m) ans=max(ans,queryma(ql,qr,2*cur+1));
	return ans;
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,n,1);
		while(q--)
		{
			int ql,qr;
			scanf("%d %d",&ql,&qr);
			printf("%d\n",queryma(ql,qr,1)-querymi(ql,qr,1));
		}
	return 0;
}
