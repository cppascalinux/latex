#include<bits/stdc++.h>
using namespace std;
int selec(int a,int b)
{
	if(a>b)swap(a,b);
	if(a%3==0&&b%3!=0)return b;
	return a;
}
int main()
{
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		long long ans=0;
		while(n>=2&&m>=2)
		{
			int ff=selec(n,m),oth=n+m-ff;
			if(ff==m)swap(n,m);
			ans+=ff/3+(ff%3==2);
			m-=2;
			if(ff%3==1)
			{
				ans+=oth/3+(oth%3==2);
				n-=2;
			}
		}
		if(n>m)swap(n,m);
		if(n==1)ans+=m/3+(m%3==2);
		cout<<ans<<endl;
	}
	return 0;
}
