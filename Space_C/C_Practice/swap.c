#include <stdio.h>
#include <stdlib.h>

#define CHAR_BITS	8

// https://aticleworld.com/c-interview-questions/2/
// Write an Efficient C Program to Reverse Bits of a Number?
// 
void prtDec2Nib(int a)
{
	int pos = sizeof(int) * CHAR_BITS-1;
	for (int i = pos; i >= 0; i--)
		a& (0x1 << i) ? printf("1") : printf("0");
}
int reverseBits(int a)
{
	int pos = sizeof(int) * CHAR_BITS - 1;
	int b = 0;
	for (int i = pos, j = 0; i >= 0; i--, j++)
	{
		if (a & (0x1 << i)) b |= (0x1 << j);
	}
	prtDec2Nib(b);
	return b;
}

int reverseBit_Algo(int a)
{
	a = (((a & 0xaaaaaaaa) >> 1) | ((a & 0x55555555) << 1));
	a = (((a & 0xcccccccc) >> 2) | ((a & 0x33333333) << 2));
	a = (((a & 0xf0f0f0f0) >> 4) | ((a & 0x0f0f0f0f) << 4));
	a = (((a & 0xff00ff00) >> 8) | ((a & 0x00ff00ff) << 8));
	
	return (a >> 16 | a << 16);
}

int CheckPowerOftwo(unsigned int x)
{
	int a;
	a = ((x != 0) && (!(x & (x - 1))));
	printf("%d, %d, %d, %d, a=%d\n",x,  (x != 0), (x & (x - 1)), !(x & (x - 1)),a );
	//return ((x != 0) && (!(x & (x - 1))));
	return a;
}

void swapInt(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void swapString(char** a, char** b)
{
	char* t = *a;
	*a = *b;
	*b = t;
}
void swapStrArray(char a[], char b[])
{
	char* t = (char*)malloc(strlen(a) + 1);
	strcpy(t, a);
	strcpy(a, b);
	strcpy(b, t);
	free(t);
}

void swapIntArray(int a[], int b[], int size)
{
	int* t = (int*)malloc(size * sizeof(int));
	memcpy(t, a, size);
	memcpy(a, b, size);
	memcpy(b, t, size);
	free(t);
}
int main()
{
	{
		int a = 10;
		int b = 20;
		swapInt(&a, &b);
		printf("a=%d, b=%d\n", a, b);		
	}
	{
		char* a = "123456";
		char* b = "abcd";
		swapString(&a, &b);
		printf("a=%s, b=%s\n", a, b);
	}
	{
		char a1[20]= "123456";
		char b1[20] = "abcd";
		swapStrArray(a1, b1);
		printf("a=%s, b=%s\n", a1, b1);
	}
	{
		int a[20] = { 10,11,12,13,14 };
		int b[20] = {20,21,22,23};
		swapIntArray(a, b,sizeof(a)/sizeof(a[0]));
		printf("a=%d, b=%d\n", a[0], b[0]);
	}

	union AA
	{
		char a;
		int b;
	}test;

	test.b = 0x12345678;
	printf("%p\n", test.b);
	if (test.a == 0x78) printf(" LE\n");
	else printf(" BE\n");
	


	printf("%d %d %d %d\n", -1 << 4, -1 >> 4, -30 << 1, -30 >> 1);
	// -16, -1, -60, -15
	printf("%d %d %d %d\n", 1 << 4, 1 >> 4, 30 << 1, 30 >> 1);    
	// 16, 0, 60, 15

	CheckPowerOftwo(5) ? printf("True\n") : printf("false\n");

	int a = 99;

	prtDec2Nib(a);
	printf("\n");
	reverseBits(a);
	int b = 0;
	b = reverseBit_Algo(a);
	printf("\n");
	prtDec2Nib(b);

}