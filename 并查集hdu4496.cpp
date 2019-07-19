#include <bits/stdc++.h>
using namespace std;
#define N 500005
int n,m;
int fa[N];
int a[N],b[N],c[N];

int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);    
}

int main()
{
	int d,e,num;
	ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m)
    {
    	a[0]=num=n;
        for(int i=0;i<n;i++)
            fa[i]=i;
        for(int i=0;i<m;i++)
            cin>>b[i]>>c[i];
           
        for(int i=m-1;i>=0;i--)
        {
             d=find(b[i]);
             e=find(c[i]);
             if(d!=e)
             {
             	fa[d]=e;
             	num--;
			 }
			 a[m-i]=num;
        }
        for(int i=m-1;i>=0;i--)
        {
             cout<<a[i]<<endl;
        }
    }
    return 0;
}

