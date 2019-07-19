#include <bits/stdc++.h>
using namespace std;
char a[10005],b[1000005];
int net[10005];
int lena,lenb,f,s;

void getnext()
{
	int i=0;
	int j=net[0]=-1;
	while(i<lena)
	{
		if(j==-1 || a[i]==a[j])
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
	while(i<lenb)
	{
		if(j==-1 || b[i]==a[j])
		{
			i++;
			j++;
		}
		else
		j=net[j];
		
		if(j==lena)
		{
			j=net[j];
			s++;
		}
	}
	return s;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		
		scanf("%s",a);
		scanf("%s",b);
		lena=strlen(a);
		lenb=strlen(b);
		getnext();
		f=kmp();
		printf("%d\n",f);
	}
	return 0;
}
