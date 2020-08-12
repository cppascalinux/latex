#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define DB double
#define EPS 1e-6
#define VET vector<edge>::iterator
#define GC() (p1==p2&&(p2=(p1=buf1)+fread(buf1,1,10000000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char *p1,*p2,buf1[10000009];
struct edge
{
	int v,w,l;
};
int n,m;
int deg[200009],sm[200009];
DB f[200009],g[200009];
vector<edge> e1[200009],e2[200009];
void rd(int &x)
{
	char c=0,inv=0;
	x=0;
	while(c<'0'||c>'9')
		c=GC(),c=='-'&&(inv=1);
	while(c>='0'&&c<='9')
		x=x*10+(c&15),c=GC();
	inv&&(x=-x);
	// scanf("%d",&x);
}
void getf()
{
	for(int i=1;i<=n;i++)
		for(VET p=e1[i].begin();p!=e1[i].end();p++)
			deg[p->v]++;
	queue<int> q;
	f[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(VET p=e1[x].begin();p!=e1[x].end();p++)
		{
			f[p->v]+=f[x]*p->w/sm[x];
			if(!--deg[p->v])
				q.push(p->v);
		}
	}
}
void getg()
{
	for(int i=1;i<=n;i++)
		for(VET p=e2[i].begin();p!=e2[i].end();p++)
			deg[p->v]++;
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!deg[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(VET p=e2[x].begin();p!=e2[x].end();p++)
		{
			g[p->v]+=(g[x]+p->l)*p->w/sm[p->v];
			if(!--deg[p->v])
				q.push(p->v);
		}
	}
}
void solve()
{
	DB ans=g[1];
	int ai=0;
	for(int i=1;i<=n;i++)
		for(VET p=e1[i].begin();p!=e1[i].end();p++)
		{
			DB nv=g[1]-f[i]*g[i];
			if(e1[i].size()>1)
				nv+=f[i]*(g[i]*sm[i]-(g[p->v]+p->l)*p->w)/(sm[i]-p->w);
			ans=min(ans,nv);
			// if(nv<ans)
			// 	ans=nv,ai=i;
			// printf("i:%d v:%d nv:%lf\n",i,p->v,nv);
		}
	if(abs(ans)<=EPS)
		ans=0;
	cerr<<g[1]<<" "<<ans;
	printf("%.3lf",ans);
}
void dbg()
{
	for(int i=1;i<=n;i++)
		printf("i:%d f:%lf g:%lf\n",i,f[i],g[i]);
}
int main()
{
	freopen("return.in","r",stdin);
	freopen("return.out","w",stdout);
	rd(n),rd(m);
	for(int i=1,a,b,c,d;i<=m;i++)
	{
		rd(a),rd(b),rd(c),rd(d);
		sm[a]+=c;
		e1[a].push_back(edge{b,c,d});
		e2[b].push_back(edge{a,c,d});
	}
	getf();
	getg();
	// dbg();
	solve();
	return 0;
}