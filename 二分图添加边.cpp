#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> Vec[100100];
int vis[100100];
ll a1,a2;
int n;
void dfs(int x,int step)
{
    for(int i=0;i<Vec[x].size();i++)
    {
        if(!vis[Vec[x][i]])
        {
            vis[Vec[x][i]]=1;
            if(step%2==1) a1++;
            else
                a2++;
            dfs(Vec[x][i],step+1);
        }
    }
}
int main()
{
    int x,y;
    a1=1;a2=0;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        Vec[x].push_back(y);
        Vec[y].push_back(x);
    }
    vis[1]=1;
    dfs(1,0);
    cout<<a1*a2-(n-1)<<endl;
    return 0;
}


