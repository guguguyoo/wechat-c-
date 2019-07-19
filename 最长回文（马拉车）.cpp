#include <bits/stdc++.h>
using namespace std;
char s[230000],a[110005];
int p[230000];
int len;
void manacher()
{
	int mx=0,id;
	for(int i=1;i<len;i++)
	{
		if(i<mx)
		p[i]=min(p[2*id-i],p[id]+id-i);
		else
		p[i]=1;
		for(;s[i+p[i]]==s[i-p[i]];p[i]++);   //左边有$,右边有0，一直比下去就好了 
		
		if(mx<p[i]+i)
		{
			mx=p[i]+i;
			id=i;
		}
	}
	int ans=0;
	for(int i=0;i<len;i++)
	ans=max(ans,p[i]);
	printf("%d\n",ans-1);
}
int main()
{
	while(~scanf("%s",a))
	{
		len=strlen(a);
		s[0]='$';
		s[1]='#';
		for(int i=0;i<len;i++)
		{
			s[i*2+2]=a[i];
			s[i*2+3]='#';
		}
		len=len*2+2;
		s[len]=0;
		manacher();
	}
	return 0;
}
