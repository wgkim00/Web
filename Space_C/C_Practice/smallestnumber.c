#include <stdio.h>
#include <math.h>

int isPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0) return 0;
	}
	return 1;
}

int maxNum(int i, int test)
{
	int multi = 0;

	for (int init = 1; ; init++)
	{
		multi = i * init;
		if (test > multi) continue;
		else break;		
	}

	return multi;
}


int main()
{
	int test = 10;
	unsigned long long small = 1;

	for (int i = 2; i <= test; i++)
	{
		if (isPrime(i))
		{

		}
	}
}