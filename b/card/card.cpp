#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
#define PLI pair<LL,int>
#define FI first
#define SE second
using namespace std;
int n;
LL sv[400009];
int lp[400009],rp[400009];
int vis[400009];
void solve()
{
	priority_queue<PLI> pq;
	for(int i=1;i<=n;i++)
	{
		lp[i]=i-1,rp[i]=i+1;
		pq.push(PLI(sv[i],i));
	}
	lp[1]=rp[n]=0;
	LL ans=0;
	int tot=n;
	while(!pq.empty())
	{
		PLI x=pq.top();
		pq.pop();
		if(vis[x.SE])
			continue;
		printf("%lld\n",ans+=x.FI);
		int p=x.SE;
		vis[p]=1;
		if(lp[p]&&rp[p])
		{
			int tl=lp[p],tr=rp[p];
			vis[tl]=vis[tr]=1;
			int np=++tot;
			sv[np]=sv[tl]+sv[tr]-sv[p];
			if(lp[tl])
				rp[lp[tl]]=np,lp[np]=lp[tl];
			if(rp[tl])
				lp[rp[tr]]=np,rp[np]=rp[tr];
			// printf("p:%d tl:%d tr:%d np:%d nv:%lld lp:%d rp:%d\n",p,tl,tr,np,sv[np],lp[np],rp[np]);
			pq.push(PLI(sv[np],np));
		}
		else
		{
			int tl=lp[p],tr=rp[p];
			// printf("p:%d tl:%d tr:%d tll:%d trr:%d\n",p,tl,tr,lp[tl],rp[tr]);
			vis[tl]=vis[tr]=1;
			rp[lp[tl]]=lp[rp[tr]]=0;
		}
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",sv+i);
	solve();
	return 0;
}