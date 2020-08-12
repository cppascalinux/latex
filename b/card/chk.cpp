#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	char s[100];
	while(1)
	{
		system("./gen;time ./card;time ./bf");
		if(system("diff card.out bf.out"))
		{
			printf("WA\n");
			break;
		}
		else
			printf("AC\n");
	}
	return 0;
}