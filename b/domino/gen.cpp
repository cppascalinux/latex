#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
using namespace std;
int main()
{
	freopen("domino.in","w",stdout);
	random_device rnd;
	int t=10;
	printf("%d\n",t);
	while(t--)
	{
		printf("%d %d\n",rnd()%100000+1,rnd()%100000+1);
	}
	return 0;
}