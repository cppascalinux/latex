#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
using namespace std;
int n=200000;
int main()
{
	freopen("card.in","w",stdout);
	random_device rnd;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",rnd()%1000000000+1);
	return 0;
}