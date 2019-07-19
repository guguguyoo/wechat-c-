#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 400005
ll a[N];   
struct node{
	ll l,r,val;
}p[N];

void pushup(ll cur)
{
	p[cur].val=p[2*cur].val+p[2*cur+1].val;   //���ڵ��������ӽڵ�ĺͣ�һֱ���ϴ�ֵ������ʹ���ڵ��������˵ĸ���
}
void build(ll l,ll r,ll cur)
{
	ll m=(l+r)/2;
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
void update(ll ul,ll ur,ll cur)
{
	ll l=p[cur].l,r=p[cur].r;
	if(ul<=l && ur>=r && p[cur].val==r-l+1) return;
	if(l==r)      //�ﵽҶ�ڵ�͸��� 
	{
		p[cur].val=sqrt(p[cur].val);
		return;
	}
	ll m=(l+r)/2;
	if(ul<=m) update(ul,ur,2*cur);
	if(ur>m) update(ul,ur,2*cur+1);
	pushup(cur);
}
ll query(ll ql,ll qr,ll cur)  //��ѯ����ֵ
{
	ll l=p[cur].l,r=p[cur].r;
	if(ql<=l && qr>=r) return p[cur].val;  //���һ�����Ľڵ����ڵ������ܹ�������������ȫ�������������ڣ�����ô��ֱ�ӷ��ظ�����ֵ
	ll m=(l+r)/2,ans=0;
	if(ql<=m) ans+=query(ql,qr,2*cur);     //���������ȫ��������ȥ���������Һ���
	if(qr>m) ans+=query(ql,qr,2*cur+1);
	return ans;
}
int main()
{
	ll n,m,t=1;
	while(scanf("%lld",&n)!=EOF)
	{
		for(ll i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		build(1,n,1);
		scanf("%lld",&m);
		printf("Case #%lld:\n",t++);
		for(ll i=1;i<=m;i++)
		{
			ll q,x,y;
			scanf("%lld%lld%lld",&q,&x,&y);
			if(x>y) swap(x,y);
			if(q==0) update(x,y,1);
			else printf("%lld\n",query(x,y,1));
		}
		printf("\n");
	}
	return 0;
}
