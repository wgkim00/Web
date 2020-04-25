#include <stdio.h>
#include <math.h>
#include <time.h>


#define _FACTOR_ 1
#define _PRIME_SUM_ 0

#if _FACTOR_
int factorize(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0) return 0;
	}
	return 1;
}
#endif


// distinguish whether the given number is a prime number or not
// 0 : not prime, 1: prime
int is_prmNum(int num)
{
	if (num < 2) return 0;

	for (int i = 2; i <= (int)sqrt(num); i++)
	{
		if (num % i == 0) return 0;
	}
	
	return 1;
}

int main()
{
	int num = 180;//2000000;
	int loop = 1;
	int num1=1, num2=1;

#if _FACTOR_

	if (num < 2) return 1;
	printf("num=%d !!!\n", num);
	num1 = num;

	for (int i = 2;i<=num1 ; i++)
	{
		// num 보다 작은 소수를 찾는다.
		// num을 소수로 나누어 나머지가 0이 아닐때 까지 반복한다.
		//
		if (is_prmNum(i))
		{

			while (num1 % i == 0)
			{
				printf("%d ",i);
				num1 /= i;
			}
		}

	}

	printf("\n");
#endif //_FACTOR_


#if _PRIME_SUM_
	int cntPrime = 0;
	unsigned long long sum = 0;

#if 1
	clock_t start_t, end_t;
	start_t = clock();
	for (num1 = 2; num1 <= num; num1++)
	{
		if (is_prmNum(num1))
		{
			//printf("%d ", num1);
			cntPrime++;
			sum += num1;
		}
	}
	end_t = clock();
	printf("\n %d has %d prime numbers. sum = %llu. elip_time=%.1lf\n", 
		num, cntPrime,sum, (double) (end_t-start_t)/CLOCKS_PER_SEC);



	// should be::: 2000000--> *** the sum of prime numbers = 142913828922 , maxNum(count)=148933



#else	// test code
	for (int i = 2; i <= 64; i++)
	{
		int my1 = is_prmNum(i);
		printf("### %d is %s \n", i, my1==1?"prime":"non-prime");
	}

#endif


#endif
}