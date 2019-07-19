#include <bits/stdc++.h>
using namespace std;

struct node{
	long long x;
	long long y;
}a[100005];

bool cmp(node x,node y)
{
	return x.x-y.x>x.y-y.y;
}
int main()
{
	long long n,s=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	cin>>a[i].x>>a[i].y;
	
	sort(a+1,a+1+n,cmp);
	
	for(long long i=1;i<=n;i++)
	s=s+a[i].x*(i-1)+a[i].y*(n-i);
	
	cout<<s<<endl;
}
