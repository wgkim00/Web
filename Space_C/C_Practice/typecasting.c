#include <stdio.h>

int masking_digit(float f)
{
	int a = f * 100;
	if (a < 0) a *= -1;
	return a%100;
}
int main()
{
	float f = -12.983456f;
	printf("%2d\n", masking_digit(f));

}