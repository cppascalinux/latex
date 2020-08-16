#include<bits/stdc++.h>
using namespace std;
int a[200005],g[200005],gs[200005];
long long dp[2005][2005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=2000)
	{
		for(int i=1;i<=n;i++)dp[i][1]=max(dp[i-1][1],1ll*a[i]);
		for(int i=1;i<=n;i++)for(int j=2;(j<<1)<=i+1;j++)
			dp[i][j]=max(dp[i-1][j],dp[i-2][j-1]+a[i]);
		for(int i=1;(i<<1)<=n+1;i++)
		{
			long long ans=0;
			for(int j=1;j<=n;j++)ans=max(ans,dp[j][i]);
			printf("%lld\n",ans);
		}
		return 0;
	}
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1&&a[i-1]==2)gs[++tot]=g[i-1];
		g[i]=(a[i]==a[i-1])*g[i-1]+1;
	}
	int ans=0;
	for(int i=1;i<=tot;i++)ans+=(gs[i]+1)/2;
	for(int i=1;(i<<1)<=n+1;i++)
	{
		if(i<=ans)printf("%d\n",i*2);
		else printf("%d\n",ans*2+(i-ans));
	}
	return 0;
}
