#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
ll sum[N],ls[N];
ll lsree[N];
int n,k,nn,c;
void add(int x)
{
	while(x<=nn)//nnΪ���ޣ�Ҫ������ɢ�������������
	{
		lsree[x]++;
		x+=x&-x;   //���ϸ���
	}
}
ll query(int x)
{
	ll s=0;
	while(x)
	{
		s+=lsree[x];
		x-=x&-x;   //�������
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
		ls[i]=sum[i]=sum[i-1]+a-k;   //Ԥ�����sum[i]����
	}
	sort(ls,ls+1+n);   //������n+1�����ֵ��򣨰�����sum[0]��
	c=unique(ls,ls+1+n)-ls;   //ȥ��
	for(int i=0;i<=n;i++)
	sum[i]=lower_bound(ls,ls+1+c,sum[i])-ls+1;  //��ɢ�� 
	
	ll s=0;
	for(int i=0;i<=n;i++)
	{
		s+=query(sum[i]);  //��ѯ�ж��ٸ�С��sum[i]������
		add(sum[i]);   //���� 
	}
	printf("%lld\n",s);
	return 0;
}
