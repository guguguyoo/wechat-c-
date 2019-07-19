#include <bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
	
	while(cin>>n>>m)
	{
	int f=1,s=0;
	int x[100001]={0},y[100001]={0},xy[100001]={0};
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		xy[x[i]]++;
		xy[y[i]]++;
	}
	sort(xy+1,xy+1+n);
	for(int i=1;i<=n;i++)
	if(xy[i]!=2)
	{
		f=0;
		s++;
		break;
	}
	if(f==1) cout<<"ring topology"<<endl;
	else
	{
	f=1;
	for(int i=3;i<=n;i++)
	{
		if(xy[1]!=1 || xy[2]!=1 || xy[i]!=2)
		{
			f=0;
			s++;
		    break;
		}
	}
	if(f==1) cout<<"bus topology"<<endl;
	else
	{
	f=1;
	for(int i=1;i<=n-1;i++)
	{
		if(xy[n]!=m && xy[i]!=1)
		{
			f=0;
			s++;
		    break;
		}
	}
	if(f==1) cout<<"star topology"<<endl;
	else
	cout<<"unknown topology"<<endl;
	}
	
	}
	
	}
	return 0;
}
