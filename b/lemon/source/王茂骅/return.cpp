#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int> > >g[1005],g2[1005],k;
double d[1005],qw[1005];
int deg[1005],deg2[1005],q[10005],vist[1005],n,m;
double solve()
{
	int head=0,tail=0;
	double ans=0;
	q[++tail]=1;
	d[1]=1;
	while(head<tail)
	{
		int p=q[++head];
		long long he=0;
		for(int i=0;i<g2[p].size();i++)he+=g2[p][i].second.first;
		for(int i=0;i<g2[p].size();i++)
		{
			int cu=g2[p][i].first;
			double e=1.0*g2[p][i].second.first/he;
			d[cu]+=d[p]*e;
			qw[cu]+=e*qw[p]+g2[p][i].second.second*e*d[p];
			deg[cu]--;
			if(!deg[cu])q[++tail]=cu;
		}
		if(he==0)ans+=qw[p];
	}
	return ans;
}
void dfs(int x)
{
	if(vist[x])return;
	vist[x]=1;
	for(int i=0;i<g[x].size();i++)dfs(g[x][i].first);
}
int main()
{
	freopen("return.in","r",stdin);
	freopen("return.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w,l;
		scanf("%d%d%d%d",&u,&v,&w,&l);
		g[u].push_back(make_pair(v,make_pair(w,l)));
	}
	dfs(1);
	for(int i=1;i<=n;i++)for(int j=0;j<g[i].size();j++)
	{
		int cu=g[i][j].first;
		if(vist[i])deg[cu]++,deg2[cu]++;
	}
	for(int i=1;i<=n;i++)g2[i]=g[i];
	double ans=1e100;
	ans=min(ans,solve());
	for(int i=1;i<=n;i++)deg[i]=deg2[i];
	for(int i=1;i<=n;i++)for(int j=0;j<g[i].size();j++)
	{
		int cu=g[i][j].first;
		for(int l=1;l<=n;l++)g2[l]=k;
		memset(d,0,sizeof(d));
		memset(qw,0,sizeof(qw));
		if(vist[i])
		{
			deg[cu]--;
			if(!deg[cu])
				for(int l=0;l<g[cu].size();l++)deg[g[cu][l].first]--;
		}
		for(int l=1;l<=n;l++)for(int p=0;p<g[l].size();p++)
		{
			if(i==l&&j==p)continue;
			g2[l].push_back(g[l][p]);
		}
		ans=min(ans,solve());
		for(int l=1;l<=n;l++)deg[l]=deg2[l];
	}
	printf("%.3f\n",ans);
	return 0;
}
