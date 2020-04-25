#include <stdio.h>
#include <time.h>

// find and add prime numbers
// summation of prime numbers

#if 0
int isPrime(unsigned int num)
{
	unsigned int div = 2;
	// num is greater than 2
	while (1)
	{
		if (num % div == 0)
			if (num == div) return 1;
			else return 0;
		else
		{
			if (num > div) div++;
			else return 0;
		}
	}
}
#else
static int maxNum = 2;
unsigned int div[1000000];
int isPrime(unsigned int num)
{
	int i = 0;
	div[0] = 2;
	div[1] = 3;
	unsigned int tmpDiv=0;

	// num is greater than 2
	for (i = 0; i < maxNum; i++)
	{
		if (num > div[i])
		{
			if (num % div[i] == 0) return 0;
		}
		else
		{
			if (num % div[i] == 0) return 1;
		}
	}
	tmpDiv = div[i-1];
	//printf("[%d] tmpDiv=%d\n", __LINE__, tmpDiv);

#if 1// good
	while (1)
	{	
		if (num > tmpDiv)
			if (num % tmpDiv == 0) return 0;// non-prime!!!
			else tmpDiv++;
		else break;;
	}
#else
	while (sqrt(num) >= tmpDiv)
	{
			if (num % tmpDiv == 0) return 0;// non-prime!!!
			else tmpDiv++;
	}
#endif
	div[maxNum++] = tmpDiv;
#if 0
	printf("[%d] tmpDiv=%d\n", __LINE__, tmpDiv);
	for( i=0;i< maxNum;i++)
		printf("[%d] div=%d\n", __LINE__, div[i]);
#endif
	return 1;
}
#endif

int main()
{
	unsigned long long num = 2000000, sum=0;/**/
	// 2000000--> *** the sum of prime numbers = 142913828922 , maxNum(count)=148933
	printf("***Begin!\n");


	clock_t start_t, end_t;
	start_t = clock();
	for (int i = 2; i < num; i++)
	//for (int i = 2; i <= sqrt(num); i++)
	{
		if (isPrime(i))
		{
			//printf("%d ", i);
		}
	}
	end_t = clock();
	for (int i = 0; i < maxNum; i++)
		sum += div[i];

	printf("\n\n***sum = %llu , maxNum=%d, elipted time=%.1lf", 
		sum, maxNum, (double)(end_t-start_t)/CLOCKS_PER_SEC); /**/

}