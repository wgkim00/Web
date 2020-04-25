// https://www.examveda.com/c-program/practice-mcq-question-on-arrays-and-strings/
#include <stdio.h>

int main()
{
	{
		int a[5] = { 5,1,15,20,25 };
		int i = ++a[1];		// i= 2, a[1]=2
		int j = a[1]++;		// j=2, a[1]=3
		int m = a[i++];		// m=a[2]=15, i=3
		printf("%d %d %d\n", i, j, m);
	}
	{
		char p;
		char buf[10] = { 1,2,3,4,5,6,9,8 };
		p = (buf + 1)[5];
		printf("p=%d\n", p);
	}
	{
		typedef char x[5];
		x myArr[10];
		printf("sizeof(&myArr)=%d, sizeof(myArr)=%d, sizeof(myArr[0])=%d\n",
			sizeof(&myArr), sizeof(myArr), sizeof(myArr[0]));
		// sizeof(&myArr)=8, sizeof(myArr)=50, sizeof(myArr[0])=5
	}
	{
		int arr[] = { 1,2,3,4,5 };
		printf("arr[5]=%d\n", arr[5]);		// 0
	}
	{
		char str1[] = "abcd";
		char str2[] = "abcd";
		if (str1 == str2) printf("Equal\n");
		else printf("Unequal\n");			// Unequal
	}
	{
		int ar[5] = { 1,2,3,4,5 };
		printf("arr[-1]=%d, arr[5]=%d\n", ar[-1], ar[5]);
		// no error, but both have garbage values
	}
	{
		int arr[5];
		printf("arr=%p, &arr=%p, sizeof(arr)=%d\n", arr, &arr, sizeof(arr));
		printf("arr+1=%p, &arr+1=%p\n", arr + 1, &arr + 1);
		//printf("&(arr+1)=%p\n", &(arr + 1));	// error C2102: '&' requires l-value
/*
arr=000000BA85FDF898, &arr=000000BA85FDF898, sizeof(arr)=20
arr+1=000000BA85FDF89C, &arr+1=000000BA85FDF8AC
 */
	}
	{
		char str1[20] = "hello";
		char str2[20] = "world";
		printf("str1=%s\n", strcpy(str2, strcat(str1, str2)));
		// helloworld 
	}
	{
		printf(5 + "Good morning\n");	// morning
	}
	{
		char str[] = "Exam\0Vera";
		printf("%s", str);		// Exam
	}

}