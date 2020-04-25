#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[2][3] = { {1,2,3},{4,5,6} };
	int(*pa)[3] = a;

	printf("a=%p\n", a);
	printf("pa=%p\n", pa);
	printf("*pa=%p\n", *pa);
	printf("&(*pa)[0]=%p\n", &(*pa)[0]);
	printf("*(pa+1)=%p\n", *(pa+1));
	printf("&(*(pa+1))[0]=%p\n", &(*(pa+1))[0]);
}