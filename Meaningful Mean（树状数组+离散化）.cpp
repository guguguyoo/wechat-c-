#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
ll sum[N],ls[N];
ll lsree[N];
int n,k,nn,c;
void add(int x)
{
	while(x<=nn)//nn为上限，要大于离散化后的最大的数字
	{
		lsree[x]++;
		x+=x&-x;   //向上更新
	}
}
ll query(int x)
{
	ll s=0;
	while(x)
	{
		s+=lsree[x];
		x-=x&-x;   //向下求和
	}
	return s;
}
int main()
{
	scanf("%d %d",&n,&k);
	nn=n+5;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		ls[i]=sum[i]=sum[i-1]+a-k;   //预处理出sum[i]数组
	}
	sort(ls,ls+1+n);   //排序，排n+1个数字的序（包括了sum[0]）
	c=unique(ls,ls+1+n)-ls;   //去重
	for(int i=0;i<=n;i++)
	sum[i]=lower_bound(ls,ls+1+c,sum[i])-ls+1;  //离散化 
	
	ll s=0;
	for(int i=0;i<=n;i++)
	{
		s+=query(sum[i]);  //查询有多少个小于sum[i]的数字
		add(sum[i]);   //更新 
	}
	printf("%lld\n",s);
	return 0;
}
