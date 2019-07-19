#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100005
int tree[N][30];
int tot;
int sum[N];
char a[N][30];

void insert(char *str)
{
    int len=strlen(str);
    int rt=0;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(tree[rt][id]==0)
    	tree[rt][id]=++tot;
        sum[tree[rt][id]]++;
        rt=tree[rt][id];
    }
}
string find(char *str)
{
    int len=strlen(str);
    int rt=0;
    string ans="";
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        rt=tree[rt][id];
        ans+=str[i];
        if(sum[rt]==1)
        return ans;
    }
}
int main()
{
    int tt=0;
    while(scanf("%s",a[tt])!=EOF)
    {
        insert(a[tt]);
        tt++;
    }
    for(int i=0;i<tt;i++)
    {
        string ss=find(a[i]);
        printf("%s %s\n",a[i],ss.c_str());
    }
    return 0;
}
