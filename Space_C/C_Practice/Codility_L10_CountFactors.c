#include <stdio.h>
#include <math.h>

int getFact(int num)
{
	unsigned int i = 1;
	unsigned int numFac = 2;

	if (num == 1) return 1;
	for (i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
		{
			if (pow(i, 2) == num)
			{
				numFac += 1;
			}
			else
			{
				numFac += 2;
			}
			printf("%d ", i);
		}

	return numFac;
}
int main()
{
	int num = 4999696;
	int cnt = 0;

	//for(num=1;num<)
	cnt=getFact(num);
	printf("\n -**cnt=%d\n", cnt);
}