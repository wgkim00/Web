#include <stdio.h>
#include <math.h>

int main()
{
	int a = 0, b = 0, c = 0;
	printf(" a  b  c \n");
	for (a = 1; a <= 500; a++)
	{
		for (b = a/**/; b <= 500; b++)
		{
			for (c = b/**/; c <= 500; c++)
			{
				if ((a * a) + (b * b) == (c * c))/**/
				{
					if( a+b+c==1000)/**/
					printf("(%2d %2d %2d)=%llu\n", a, b, c, (unsigned long long)a*b*c);
				}
			}
		}
	}
	return 0;
}