#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std; 
const int maxn=200005;
int n,vis[maxn];
struct card
{
	long long val,id;
	bool operator <(card other) const
	{
		return val<other.val;
	}
};
struct point
{
	long long v,l,r;
}a[maxn];
priority_queue <card> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].v);
		a[i].l=i-1; a[i].r=i+1;
		q.push((card){a[i].v,(long long)i});
	}
	a[1].l=n+3; a[n].r=n+3;
	a[n+3].v=-1e16;
	long long ans=0;
	for(int i=1;i*2<=n+1;i++)
	{
		while(vis[q.top().id]) q.pop();
		card tmp=q.top(); q.pop();
		ans+=tmp.val;
		vis[a[tmp.id].l]=vis[a[tmp.id].r]=1;
		a[tmp.id].v=a[a[tmp.id].l].v+a[a[tmp.id].r].v-a[tmp.id].v;
		q.push((card){a[tmp.id].v,tmp.id});
		a[tmp.id].l=a[a[tmp.id].l].l;
		a[tmp.id].r=a[a[tmp.id].r].r;
		a[a[tmp.id].l].r=tmp.id;
		a[a[tmp.id].r].l=tmp.id;
		printf("%lld\n",ans);
	}
    return 0;
}
