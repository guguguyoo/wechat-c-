#include <bits/stdc++.h>
using namespace std;
char a[1005],b[1005];
int net[1005];
int lena,lenb,s;

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
			i++;
			j++;
		}
		else
		j=net[j];
		
		if(j==lenb)
		{
			j=0;
			s++;
		}
	}
	printf("%d\n",s);
}
int main()
{
	while(scanf("%s",a)==1)
	{
		if(a[0]=='#') return 0;
		scanf("%s",b);
		s=0;
		lena=strlen(a);
		lenb=strlen(b);
		getnext();
		kmp();
	}
	return 0;
}
