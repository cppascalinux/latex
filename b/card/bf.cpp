#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
int n;
int sv[1000009];
LL f[2][1000009][2];
void dp()
{
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		cur^=1;
		for(int j=1;j<=(i+1)>>1;j++)
		{
			f[cur][j][0]=max(f[cur^1][j][0],f[cur^1][j][1]);
			f[cur][j][1]=f[cur^1][j-1][0]+sv[i];
		}
	}
	for(int i=1;i<=(n+1)>>1;i++)
		printf("%lld\n",max(f[cur][i][0],f[cur][i][1]));
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("bf.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",sv+i);
	dp();
	return 0;
}