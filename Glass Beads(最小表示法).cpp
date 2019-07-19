#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
char a[100005];
int n,lena,ans;
int mr()
{
	int i=0,j=1,k;
	while(i<lena && j<lena)
	{
		k=0;
		while(a[i+k]==a[j+k] && k<lena) k++;
		if(k>lena) break;
		if(a[i+k]>a[j+k])
		i=i+k+1;
		else
		j=j+k+1;
		if(i==j) j++;
	}
	return min(i,j);
}
int main()
{
	cin>>n;
	while(n--)
	{
		scanf("%s",a);
		lena=strlen(a);
		for(int i=0;i<lena;i++)
		a[lena+i]=a[i];
		ans=mr()+1;
		printf("%d\n",ans);
	}
}
