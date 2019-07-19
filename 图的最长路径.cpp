#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a[2005],x,y,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		a[i]=m;
	}
	for(int i=1;i<=n;i++)
	{
		int x=1;
		y=i;
		while(a[y]!=-1)
	    {
    		x++;
    		y=a[y];
	    }
	    s=max(s,x);
	}
	cout<<s<<endl;
}
