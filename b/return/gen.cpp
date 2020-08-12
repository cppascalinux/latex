#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
#include<unordered_set>
#include<set>
#define PII pair<int,int>
using namespace std;
int n=200000,m=199999,tot=0;
int dep[1000009];
set<PII> s;
int main()
{
	freopen("return.in","w",stdout);
	random_device rnd;
	printf("%d %d\n",n,m);
	for(int i=2;i<=n;i++)
	{
		int fa=max(1,i-(int)(rnd()%5)-1);
		// fa=1;
		int w=rnd()%10+1,l=rnd()%21-10;
		// if(rnd()%10000!=0)
		// 	w=1,l=-9;
		dep[i]=dep[fa]+1;
		s.insert(PII(fa,i));
		printf("%d %d %d %d\n",fa,i,w,l);
		tot++;
	}
	while(tot<m)
	{
		int u=rnd()%n+1,v=rnd()%n+1;
		if(u==v)
			continue;
		if(s.count(PII(u,v))||s.count(PII(v,u)))
			continue;
		if(dep[u]>dep[v])
			swap(u,v);
		s.insert(PII(u,v));
		int w=rnd()%10+1,l=rnd()%21-10;
		printf("%d %d %d %d\n",u,v,w,l);
		tot++;
	}
	return 0;
}