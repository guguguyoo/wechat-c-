#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a[505][505];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>a[i][j];
	
	int s=0;
	for(int i=1;i<=n;i++)
	s^=a[i][1];
	
	if(s!=0)
	{
		cout<<"TAK"<<endl;
		for(int i=1;i<=n;i++)
		cout<<"1 ";
		cout<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
		if(a[i][j]!=a[i][1])
		{
			cout<<"TAK"<<endl;
			for(int k=1;k<=n;k++)
			if(k!=i)
			cout<<"1 ";
			else
			cout<<j<<" ";
			
			cout<<endl;
			return 0;
		}
	}
	cout<<"NIE"<<endl;
	return 0;
}
