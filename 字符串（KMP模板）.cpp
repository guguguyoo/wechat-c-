#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[100005];
int net[100005];
int lena,lenb,f;

void getnext()
{
	int i=0;
	int j=net[0]=-1;
	while(i<lenb)
	{
		if(j==-1 || b[i]==b[j])
		{
			i++;j++;
			net[i]=j;
		}
		else
		j=net[j];
	}
}
int kmp()
{
	int i=0,j=0;
	while(i<lena)
	{
		if(j==-1 || a[i]==b[j])
		{
			i++;j++;
		}
		else
		j=net[j];
		
		if(j==lenb)
		return i-j+1;
	}
	return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(net,0,sizeof(net));
		
		scanf("%d %d",&lena,&lenb);
		for(int i=0;i<lena;i++)
		scanf("%d",&a[i]);
		for(int i=0;i<lenb;i++)
		scanf("%d",&b[i]);
		
		getnext();
		f=kmp();
		printf("%d\n",f);
	}
	return 0;
}
