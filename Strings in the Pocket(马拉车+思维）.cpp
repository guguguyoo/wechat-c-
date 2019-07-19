#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000005
char s[N],t[N];
char str[N*2];
int p[N*2];
void manacher(int len)
{
	ll ans=0;
	int mx=0,id=0;
	for(int i=1;i<len;i++)
	{
		if(mx>i) p[i]=min(p[id*2-i],mx-i);
		else p[i]=1;
		
		for(;str[i+p[i]]==str[i-p[i]];p[i]++);
		
		if(i+p[i]>mx)
		{
			mx=i+p[i];
			id=i;
		}
		ans+=p[i]/2;
	}	
	printf("%lld\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	int l,r;
	while(T--)
	{
		ll ans=0;
		scanf("%s%s",s,t);
		int len=strlen(s);
		l=-1;
		for(int i=0;i<len;i++)
		{
			if(s[i]!=t[i])
			{
				l=i;
				break;
			}
		}
		if(l!=-1)
		{
			r=-1;
			for(int i=len-1;i>=0;i--)
			{
				if(s[i]!=t[i])
				{
					r=i;
					break;
				}
			}
			int j=r,flag=0;
			for(int i=l;i<=r;i++,j--)
			{
				if(s[i]!=t[j])
				{
					flag=1;
					break;
				}
			}
			if(flag)
			printf("0\n");
			else
			{
				ans=1;
				for(int i=1;i<=l && r+i<len;i++)
				{
					if(s[l-i]==s[r+i])
					ans++;
					else
					break;
				}
				printf("%lld\n",ans);
			}
		}
		else   //s==tʱ 
		{
			str[0]='$';
			str[1]='#';
			for(int i=0;i<len;i++)
			{
				str[2*i+2]=s[i];
				str[2*i+3]='#';
			}
			int llen=2*len+2;
			str[llen]='\0';
			manacher(llen);
		}
	}
}
