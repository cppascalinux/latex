#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	int t=0;
	while(1)
	{
		t++;
		system("./gen;time ./bf;time ./return");
		if(system("diff bf.out return.out"))
		{
			printf("WA%d\n",t);
			break;
		}
		else
			printf("AC%d\n",t);
	}
	return 0;
}