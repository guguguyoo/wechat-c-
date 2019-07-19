#include <bits/stdc++.h>
using namespace std;
#define M 200005
int n,k,i,j,r,sta,End;
int f[M],a[M],pre[M],suc[M],res[M];
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]=i;
        pre[i]=i-1;
        suc[i]=i+1;//位置，前驱，后继 
    }
    r=1;
    for(i=n;i>=1;i--)
    if (f[i])//找当前的最大值 
    {
        End=f[i];
        for(j=1;j<=k;j++)
        {
            if(suc[End]==n+1)break;
            End=suc[End];
            f[a[End]]=0;
			res[End]=r;
        }
        End=suc[End];

        sta=f[i];
        for(j=1;j<=k;j++)
        {
            if(pre[sta]==0)break;
            sta=pre[sta];
            f[a[sta]]=0;
			res[sta]=r;
        }
        sta=pre[sta];

        suc[sta]=End;
		pre[End]=sta;
        res[f[i]]=r;
		f[i]=0;
        r=3-r;
    }
    for(i=1;i<=n;i++) cout<<res[i]; 
	cout<<endl;
	
    return 0;
}
