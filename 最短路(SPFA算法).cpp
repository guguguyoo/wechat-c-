#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 1e5 + 10;
const int M = 1e6 + 10;

struct edge{
    int u, v, w;
} e[M];
int head[M];
int n, m, s, t, x, y, z;
int cnt = 0;

int dis[N], vis[N];

void add(int x, int y, int z){
    e[cnt].v = y;
    e[cnt].w = z;
    e[cnt].u = head[x];
    head[x] = cnt++;
}

void spfa(){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(q.empty()==false)
	{
        int k = q.front();
        q.pop();
        vis[k] = 0;
        for(int i = head[k]; i != -1; i = e[i].u)
		{
            int v = e[i].v;
            int w = e[i].w;
            if(dis[v] > dis[k] + w)
			{
                dis[v] = dis[k] + w;
                if(vis[v]==0)
				{
                    q.push(v);
                    vis[v] = 1;
                }   
            }
        }
    } 
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(dis, INF, sizeof(dis));
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while(m--)
	{
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    dis[s] = 0;
    spfa();
    printf("%d\n", dis[t]);
    return 0;
}
