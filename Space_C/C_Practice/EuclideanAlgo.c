// GCD: the greatest common divisder
#include <stdio.h>

// Using Euclidean algorithm
// https://modoocode.com/30

int getGCD(int large, int small)
{
	int remain = 0;

	remain = large % small;

	if (remain == 0) return small;
	else
	{
		remain > small ? getGCD(remain, small) : getGCD(small,remain);
	}
}

int main()
{
	int m=18, n=24, p=40, q=60;
	int gcd = 0;

#if 0
	if (m > n) gcd=getGCD(m, n);
	else gcd = getGCD(n,m);

	printf("gcd(%d,%d)=%d\n", m, n, gcd);

	if (gcd > p) gcd = getGCD(gcd, p);
	else gcd = getGCD(p, gcd);

	printf("gcd(%d,%d, %d)=%d\n", m, n, p, gcd);

	if (gcd > q) gcd = getGCD(gcd, q);
	else gcd = getGCD(q, gcd);

	printf("gcd(%d,%d, %d,%d)=%d\n", m, n, p,q, gcd);
#else
	m > n?(gcd = getGCD(m, n)): (gcd = getGCD(n, m));
	printf("gcd(%d,%d)=%d\n", m, n, gcd);

	gcd > p?(gcd = getGCD(gcd, p)):(gcd = getGCD(p, gcd));
	printf("gcd(%d,%d,%d)=%d\n", m, n, p, gcd);

	gcd > q?(gcd = getGCD(gcd, q)): (gcd = getGCD(q, gcd));
	printf("gcd(%d,%d,%d,%d)=%d\n", m, n, p, q, gcd);

	char* s = "123456789";
	printf("%s %d\n", s,strlen(s));

#endif
}