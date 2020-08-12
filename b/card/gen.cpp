#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
using namespace std;
random_device rnd;
int n=rnd()%2+199999;
int main()
{
	freopen("card.in","w",stdout);
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",rnd()%1000000000+1);
	return 0;
}