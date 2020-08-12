#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define DB double
using namespace std;
struct edge
{
	int v,w,l,id;
};
int n,m;
int deg[1000009],sm[1000009];
vector<edge> e[1000009];
DB f[1000009];
DB cal(int bid)
{
	memset(deg,0,(n+1)<<2);
	memset(sm,0,(n+1)<<2);
	memset(f,0,(n+1)<<3);
	for(int i=1;i<=n;i++)
		for(auto t:e[i])
			if(t.id!=bid)
				deg[t.v]++,sm[t.v]+=t.w;
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!deg[i])
			f[i]=0,q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto t:e[x])
			if(t.id!=bid)
			{
				f[t.v]+=(DB)t.w/sm[t.v]*(f[x]+t.l);
				if(--deg[t.v]==0)
					q.push(t.v);
			}
	}
	return f[1];
}
int main()
{
	freopen("return.in","r",stdin);
	freopen("bf.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,a,b,c,d;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		e[b].push_back(edge{a,c,d,i});
	}
	DB ans=1e300;
	int ai;
	for(int i=0;i<=m;i++)
	{
		DB v=cal(i);
		if(v<ans)
			ans=v,ai=i;
		printf("\t\t\\hline %d&%.3lf\\\\\n",i,v);
	}
	// printf("%d %.2lf\n",ai,ans);
	return 0;
}