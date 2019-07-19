#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		long long s=0;
		cin>>n;
		priority_queue<long long,vector<long long>,greater<long long> >q;   //从小到大 
		for(int j=0;j<n;j++)
		{
			long long a;
			cin>>a;
			q.push(a);
		}
		while(q.size()!=1)
		{
			long long a;
			a=q.top();
			q.pop();
			a+=q.top();
			q.pop();
			s+=a;
			q.push(a);
		}
		
		cout<<s<<endl;
		if(i!=t) cout<<endl;
	}
}
