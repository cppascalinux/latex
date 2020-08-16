#include<bits/stdc++.h>
using namespace std; 
int t,n,m;
int main()
{	
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",(n+1)*(m+1)/6);
	}
    return 0;
}
