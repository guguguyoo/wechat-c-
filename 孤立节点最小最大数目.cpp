#include <bits/stdc++.h>
using namespace std;
long long n,m;

int main()
{
	cin>>n>>m;
	long long s=0;
	long long ma,ss;
	s=max(s,n-m*2);
	if(m<=1)
	{
		cout<<s<<" "<<s;
		return 0;
	}
	
	for(int i=2;i<=n;i++)
	{
		ss=ss+i-1;
		if(ss>=m)
		{
			ma=n-i;
			break;
		}
	}
	cout<<s<<" "<<ma;
	return 0;
}
