#include<cstdio>
#define LL long long
int main()
{
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%lld\n",(LL)(n+1)*(m+1)/6);
	}
	return 0;
}