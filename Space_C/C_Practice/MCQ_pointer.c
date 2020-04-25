// https://www.examveda.com/c-program/practice-mcq-question-on-pointer/
#include <stdio.h>
#if 0
THERE ARE SEVERAL DIFFERENT USES OF POINTERS IN C...THEY ARE
(1) int* p;
// p is a pointer to an integer quantity
(2) int* p[10];
// p is a 10-element array of pointers to integer quantities
(3) int(*p)[10];
// p is a pointer to a 10-element integer array
(4) int* p(void);
// p is a function that returns a pointer to an integer quantity
(5) int p(char* a);
// p is a function that accepts an argument which is a pointer to a character returns an integer quantity
(6) int* p(char* a);
// p is a function that accepts an argument which is a pointer to a character returns a pointer to an integer quantity.
(7) int (*p)(char* a);
// p is pointer to a function that accepts an argument which is a pointer to a character returns an integer quantity.
(8) int(*p(char* a))[10];
// p is a function that accepts an argument which is a pointer to a character 
                        returns a pointer to a 10-element integer array.
(9) int p(char(*a)[]);
// p is a function that accepts an argument which is a pointer to a character array returns an integer quantity.
(10) int p(char* a[]);
// p is a function that accepts an argument which is a array of pointers to characters returns an integer quantity
(11) int* p(char a[]);
// p is a function that accepts an argument which is a character array returns a pointer to an integer quantity
(12) int* p(char(*a)[]);
// p is a function that accepts an argument which is a pointer to a character array returns a pointer to an integer quantity
(13) int* p(char* a[]);
// p is a function that accepts an argument which is an array of pointers to characters
// returns a pointer to an integer quantity
(14) int (*p)(char(*a)[]);
// p is pointer to a function that accepts an argument which is a pointer to a character array returns an integer quantity
(15) int* (*p)(char(*a)[]);
// p is pointer to a function that accepts an argument which is a pointer to a character array returns a pointer to an integer quantity
(16) int* (*p)(char* a[]);
// p is pointer to a function that accepts an argument which is a array of pointers to characters returns a pointer to an integer quantity
(17) int (*p[10])(void);
// p is 10-element array of pointers to functions; each function returns an integer quantity
(18) int (*p[10])(char a);
// p is 10-element array of pointers to functions; each function accepts an argument which is a character and returns an integer quantity
(19) int* (*p[10])(char a);
// p is 10-element array of pointers to functions; each function accepts an argument which is a character and returns a pointer to an integer quantity
(20) int* (*p[10])(char* a);
// p is 10-element array of pointers to functions; each function accepts an argument which is a pointer to a character and returns a pointer to an integer
#endif
int main()
{
	/*{
		char far* farther, * farthest;
		printf("%d..%d", sizeof(farther), sizeof(farthest));
	}
	*/
	/*{
https://en.wikipedia.org/wiki/Far_pointer
		char far* p = (char far*)0x55550005;
		char far* q = (char far*)0x53332225;
		*p = 80;
		(*p)++;
		printf("*q=%d\n", *q);
in an Intel 8086, as well as in later processors running 16 - bit code,
a far pointer has two parts : a 16 - bit segment value and a 16 - bit offset value.
A linear address is obtained by shifting the binary segment value four times to the left,
and then adding the offset value.Hence the effective address is 20 bits
(actually 21 - bit, which led to the address wraparound and the Gate A20).
There can be up to 4096 different segment - offset address pairs pointing
to one physical address.
To compare two far pointers, they must first be converted(normalized) to
their 20 - bit linear representation.

	}*/
	{
		char* str1 = "abcd";
		char str2[] = "abcd";
		printf("%d %d %d\n", sizeof(str1), sizeof(str2), sizeof("abcd"));
		// 8 5 5
		printf("%d %d %d\n", strlen(str1), strlen(str2), strlen("abcd"));
		// 4 4 4
	}
	{
		int i = 10;
		void* p = &i;
		printf("%d, %d, %f\n", *(char*)p, *(int*)p, *(float*)p);
	}
	{
		char arr[] = "1234567";
		arr[0] = 'a';
		printf("sizeof arr=%d, %s\n", sizeof arr, arr);

#if 0	
		// case1: run-time error
		char* str = "1234567";
		str = 'a';
		printf("sizeof str=%d, %s\n", sizeof str, str);


		// case2: run-time error
		char* str = malloc(sizeof(arr));
		strcpy(str, arr);
		str[0] = '1';
		printf("sizeof str=%d, %s\n", sizeof str, str);
		free(str);

#endif
		char num=10;
		char* str = &num;
		*str = 1;
		printf("sizeof str=%d, %d\n", sizeof str, *str);

	}
	{
		int a[] = { 1,2,3,4,5 }, * p;
		p = a;
		++* p;
		printf("a[0]=%d, *p=%d\n", a[0], *p);
		p += 2;
		printf("a[0]=%d, *p=%d\n", a[0], *p);
	}
	{
		char a[] = "12345", *p;
		p = a;
		a[0] = 'a';
		*p = 'b';
		printf("sizeof(a)=%d, sizeof(p)=%d,  a=%s\n", sizeof(a), sizeof(p), a);

#if 0
		// runtime error
		str = malloc(sizeof(arr1));
		strcpy(str, arr1);
		//str[0] = '1';
		*str = '1';
		printf("sizeof str=%d, %s\n", sizeof str, str);
		free(str);
#endif
	}
	{
		// https://dojang.io/mod/page/view.php?id=277
		const int a = 10;
		int* p = &a;
		*p = 20;
		printf("%d %d\n", a, *p);	// 20 20
	}
	{
		int a = 10;
		const int* p = &a;
		a = 20;
		printf("%d %d\n", a, *p);	// 20 20
	}
#if 0
	char(*Name(int(&)[3]))[3];
	Name is a function returning pointer to char array with 3 elements.
		int (*fn)(int,int)
		fn is a pointer to 2 int args
		char 요소3개인배열을가리키는포인터를반환하는
		함수
		char (*fn)[3]
#endif
}