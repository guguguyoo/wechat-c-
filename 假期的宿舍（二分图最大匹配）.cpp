#include <bits/stdc++.h>
using namespace std;
bool a[55][55];
int vis[55];
int bian[55],school[55],zhu[55];
int t,n,f;

bool find(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[x][i]==true && vis[i]==0)
		{
			vis[i]=1;
			if(bian[i]==0 || find(bian[i]))
			{
				bian[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin>>t;
	while(t--)
	{
		f=0;
		memset(a,false,sizeof(a));
		memset(bian,0,sizeof(bian));
		memset(zhu,0,sizeof(zhu));
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>school[i];
		
		for(int i=1;i<=n;i++)
		{
			int c;
			cin>>c;
			if(school[i]==1)
			{
				zhu[i]=c;      
				a[i][i]=true;    //先存自己和自己床 
			}
			
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int c;
				cin>>c;
				if(school[j]==1 && c==1)
				a[i][j]=true;        //存自己和认识的人的床 
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(zhu[i]==1) continue;    //如果自己是在校生且离校了就跳过 
			if(find(i)==false)
			{
				f=1;
				break;
			}
		}
		if(f==1) cout<<"T_T"<<endl;
		else cout<<"^_^"<<endl;
	}
	return 0;
}
