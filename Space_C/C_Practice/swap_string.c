// https://www.geeksforgeeks.org/swap-strings-in-c/
// https://dojang.io/mod/page/view.php?id=529

#include<stdio.h>
#include <stdlib.h>

void swapStringPointer(char** pp1, char** pp2)
{
	char* t = *pp2;
	*pp2 = *pp1;
	*pp1 = t;
}

void swapStringArray(char* a1, char* a2)
{
	printf("sizeof(a1)=%d,strlen(a1)=%d\n", sizeof(a1), strlen(a1));
	char* t = (char*)malloc(strlen(a1)+1);
	strcpy(t, a1);
	strcpy(a1, a2);
	strcpy(a2, t);
	free(t);
}
void swapInteger(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void swapIntArray(int a[], int b[], int sizeArr)
{
	int* t = malloc(sizeArr*sizeof(int));
	memcpy(t, a, sizeArr);
	memcpy(a, b, sizeArr);
	memcpy(b, a, sizeArr);
	free(t);
}
int main()
{
	{
		int a = 10;
		int b = 20;
		swapInteger(&a, &b);
		printf("%d %d\n", a, b);
	}
	{// swap strings for pointers
		// https://dojang.io/mod/page/view.php?id=329

		char* p1 = "Takapuna";
		char* p2 = "Milford";
		//*p1 = '1';						// write access violation.
		swapStringPointer(&p1, &p2);
		printf("%s %s\n", p1, p2);
	}
	{// swap strings for arrays
		// https://dojang.io/mod/page/view.php?id=330

		char a1[20]= "1234567890";
		char a2[20]= "abcde";
		swapStringArray(a1, a2);
	}
	{
		int a[10] = { 10,11,12,13,14, };
		int b[10] = { 20,21,22,23, };
		int size_a = sizeof(a) / sizeof(a[0]);
		int size_b = sizeof(b) / sizeof(b[0]);
		int sizeArr = size_a > size_b ? size_a : size_b;
		swapIntArray(a, b, sizeArr);
		for (int i=0; i < sizeArr; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	{
		char arr1[] = "abcdef";
		char* str = arr1;
		*str = '1';
		arr1[0] = '2';
		printf("sizeof str=%d, %s\n", sizeof str, str);

		str = malloc(sizeof(arr1));
		strcpy(str, arr1);
		*str = '1';
		printf("sizeof str=%d, %s\n", sizeof str, str);
		free(str);
	}
	{
		char* ptr = "1234567890";
		printf("%c\n", ptr[3]);
		// ptr[3] = 'a';		run-time error
		printf("%s\n", ptr);
	}
	{
		int* numPtr1;     // 단일 포인터 선언
		int** numPtr2;    // 이중 포인터 선언
		int num1 = 10;

		numPtr1 = &num1;    // num1의 메모리 주소 저장 
		numPtr2 = &numPtr1; // numPtr1의 메모리 주소 저장

		**numPtr2 = 111;
		printf("%d\n", **numPtr2);    // 20: 포인터를 두 번 역참조하여 num1의 메모리 주소에 접근
	}
}