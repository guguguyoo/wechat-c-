#include <bits/stdc++.h>
using namespace std;
#define N 500005
int n,m;
int fa[N];
int a[N];

int Find(int x)
{
    if(x==fa[x]) return x;
    
    return fa[x]=Find(fa[x]);    //  路径压缩 
}

int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    while(m--)
    {
        int k;
        cin>>k;
        if(k)
        {
            int sta;
            cin>>sta;
            for(int i=2; i<=k; i++)
            {
                int cen;
                cin>>cen;
                fa[Find(cen)]=Find(sta);   //将后面的人父亲定为第一个 
            }

        }

    }
    for(int i=1;i<=n;i++)
    {
        a[Find(i)]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[Find(i)]<<" ";
    }
    return 0;
}

