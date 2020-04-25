#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int dvd(int a, int b)
{
	return a / b;
}

#define _FNPTR_
#ifdef _FNPTR_
typedef struct stfuncs
{
	int num;
	int (*pfnPointer[4])(int, int);
}stfuncs;
#endif
int main()
{
	int (*myFunc)(int, int);
	int a = 4, b = 5;

	myFunc = add;
	printf("a=%d, b=%d, myFunc=%d\n", a, b, myFunc(a, b));

	int (*pfnArr[4])(int, int) = { add, sub,mul,dvd };
	for (int i = 0; i < 4; i++)
	{
		printf("a=%d, b=%d, pfnArr=%d\n", a, b, pfnArr[i](a, b));
	}

	for (int i = 0; i < 4; i++)
	{
		printf("**a=%d, b=%d, pfnArr=%d\n", a, b, (pfnArr[i])(a, b));
	}

#ifdef _FNPTR_
	stfuncs *mystfuncs=(stfuncs * )malloc(sizeof(stfuncs)*4);
	mystfuncs->pfnPointer[0] = add;
	mystfuncs->pfnPointer[1] = sub;
	mystfuncs->pfnPointer[2] = mul;
	mystfuncs->pfnPointer[3] = dvd;

	mystfuncs->num = sizeof(mystfuncs->pfnPointer) / sizeof(mystfuncs->pfnPointer[0]);
	for(int i=0; i< mystfuncs->num; i++)
		printf("****a=%d, b=%d, pfnPointer=%d\n", a, b, mystfuncs->pfnPointer[i](a, b));
#endif	//_FNPOINTER_


	return 0;
}