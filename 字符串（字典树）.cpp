#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int tree[N][30],ans[N];
bool f[N];
char a[N];
int t;//��¼�ڵ���Ŀ 
void insert(char *str)
{
	int len=strlen(str);
	int rt=0;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';  //��¼���ʵı�� 
		if(tree[rt][id]==0)
		tree[rt][id]=++t;   //û���ֹ��ͼ�¼һ�� 
		ans[tree[rt][id]]++;
		rt=tree[rt][id];   
	}
	f[rt]=true;
}
int find(char *str)
{
	int len=strlen(str);
	int rt=0;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';
		if(tree[rt][id]==0)   //û���־����� 
		return 0;
		rt=tree[rt][id];
		
	}
	return ans[rt];
}
int main()
{
	t=0;
	memset(ans,0,sizeof(ans));
	while(gets(a))
	{
		if(a[0]=='\0')
		break;
		insert(a);
	}
	while(gets(a))
	{
		printf("%d\n",find(a));
	}
	return 0;
}
