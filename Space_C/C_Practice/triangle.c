#include <stdio.h>

int isPrime(int num)
{
	int i = 2;
	if (num < 2) return 0;
	else if (num == 2) return 1;

	while (1)
	{
		if (num % i == 0)
		{
			if (num ==i) return 1;
			else return 0;
		}
		else
			i++;
	}
}


int main()
{
	unsigned long long sum = 0UL;
	int i;
	for (i = 2; i <= 2000000; i++)
	{
		if (isPrime(i))
		{
			//printf("%d ", i);
			sum += i;
		}
	}
	printf("\n%lld\n", sum);
}