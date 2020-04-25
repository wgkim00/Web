#include <stdio.h>
#include <stddef.h>
#include <locale.h>

// https://www.examveda.com/c-program/practice-mcq-question-on-control-structures

int main()
{
	{
		int i = -10;
		for (; i; printf("%d ", i++));
		// -10 -9 -8 -7 -6 -5 -4 -3 -2 -1
	}
	{
		printf("\n");
		int arr[3][5];
		printf("&arr[0][0]=%p, &arr[0][1]=%p, &arr[1][0]=%p\n",
			&arr[0][0], &arr[0][1], &arr[1][0]);
		printf("&arr[0]=%p, &arr[1]=%p\n", &arr[0], &arr[1]);
		printf("*arr=%p, *(arr+1)=%p, *arr+1=%p\n", *arr, *arr + 1, *(arr + 1));
		printf("arr=%p, arr+1=%p\n", arr, arr + 1);
		printf("&arr=%p, &arr+1=%p\n", &arr, &arr + 1);
		// &(arr + 1) : error
		printf("sizeof(&arr)=%d, sizeof(arr)=%d, sizeof(arr[0])=%d, sizeof(arr[0][0])=%d\n",
			sizeof(&arr), sizeof(arr), sizeof(arr[0]) , sizeof(arr[0][0]));
		printf("sizeof(arr)/sizeof(arr[0])=%d, sizeof(arr[0])/sizeof(arr[0][0])=%d\n",
			sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]) / sizeof(arr[0][0]));
		printf("sizeof(arr)/sizeof(*arr)=%d, sizeof(*arr)/sizeof(**arr)=%d\n",
			sizeof(arr) / sizeof(*arr), sizeof(*arr) / sizeof(**arr));
		/*
&arr[0][0]=00000081A6B3F458, &arr[0][1]=00000081A6B3F45C, &arr[1][0]=00000081A6B3F46C
&arr[0]=00000081A6B3F458, &arr[1]=00000081A6B3F46C
*arr=00000081A6B3F458, *(arr+1)=00000081A6B3F45C, *arr+1=00000081A6B3F46C
arr=00000081A6B3F458, arr+1=00000081A6B3F46C
&arr=00000081A6B3F458, &arr+1=00000081A6B3F494

sizeof(&arr)=8, sizeof(arr)=60, sizeof(arr[0])=20, sizeof(arr[0][0])=4 <-- keep in mind!

sizeof(&arr)=8, sizeof(arr)=60, sizeof(*arr)=20, sizeof(**arr)=4
sizeof(arr)/sizeof(arr[0])=3, sizeof(arr[0])/sizeof(arr[0][0])=5
sizeof(arr)/sizeof(*arr)=3, sizeof(*arr)/sizeof(**arr)=5
		*/
	}
	{
		char p;
		char buf[10] = { 1,2,3,4,5,6,9,8 };
		p = (buf + 1)[5];
		printf("\np=%d\n", p);	// 9
	}
	{
		// sizeof(&myArr)=8, sizeof(myArr)=200,sizeof(myArr[0])=40,sizeof(myArr[0][0])=4
		typedef int x[10];
		x myArr[5];	// --> int myArr[5][10]
		printf("sizeof(&myArr)=%d, sizeof(myArr)=%d,sizeof(myArr[0])=%d,sizeof(myArr[0][0])=%d\n",
			sizeof(&myArr), sizeof(myArr), sizeof(myArr[0]), sizeof(myArr[0][0]));
	}
	if(1)
	{
		float f;
		int n;
		char str[10];
		printf("Enter a floating number and an integer number: "); 
		// input: 1234567890
		int ret=scanf("%2[0-9]         %3[0-9] %d",&f ,str, &n);	
		// ret : the count of proper inputs
		printf("ret=%d, f=%f, str=%s, n=%d\n",ret,f,str,n); 
		// no error, but garbage...
	}
	{
		int i, j;
		float x, y;
		char str1[10], str2[4];
		wchar_t warr[2];
		setlocale(LC_ALL, "en_US.utf8");

		char input[] = "25 54.32E-1 Thompson 56789 0123 56©¬â©";
		/* parse as follows:
		   %d: an integer
		   %f: a floating-point value
		   %9s: a string of at most 9 non-whitespace characters
		   %2d: two-digit integer (digits 5 and 6)
		   %f:  a floating-point value (digits 7, 8, 9)
		   %*d: an integer which isn't stored anywhere
		   ' ': all consecutive whitespace
		   %3[0-9]: a string of at most 3 decimal digits (digits 5 and 6) <---------
		   %2lc: two wide characters, using multibyte to wide conversion  */
		int ret = sscanf(input, "%d%f%9s%2d%f%*d %3[0-9]%2lc",
			&i, &x, str1, &j, &y, str2, warr);

		printf("Converted %d fields:\ni = %d\nx = %f\nstr1 = %s\n"
			"j = %d\ny = %f\nstr2 = %s\n"
			"warr[0] = U+%x warr[1] = U+%x\n",
			ret, i, x, str1, j, y, str2, warr[0], warr[1]);

#ifdef __STDC_LIB_EXT1__
		int n = sscanf_s(input, "%d%f%s", &i, &x, str1, (rsize_t)sizeof str1);
		// writes 25 to i, 5.432 to x, the 9 bytes "thompson\0" to str1, and 3 to n.
#endif
	}
	{
		int i, j;
		for (i = 0, j = 0; i < 10, j < 20; i++, j++)
		{
			printf("i=%d, j=%d\n", i, j);
		}
		i = 5; j = 20;
		if (i < 10, j < 10) printf("True\n");
		else printf("False\n");
		if (i > 10, j > 10) printf("True\n");
		else printf("False\n");
	}
	{
		int value1, value2 = 100, num = 100;
		if (value1 = value2 % 5) num = 5;
		printf("%d %d %d\n", num, value1, value2);
	}
	{
		float num = 5.6f;
		//switch (num)			// error C2050: switch expression not integral
		//{
		//case 5: printf("5\n"); break;
		//case 6: printf("6\n"); break;
		//default: printf("0\n");
		//	break;
		//}
		printf("%d\n", num);	// no error
	}
	{
		int i = 1, j = -1;
		int val1, val2;
		if((val1=printf("%d ",i))<(val2=printf("%d ",j)))
			printf("%d ", i);
		else
			printf("%d ", j);
		printf("\nval1=%d, val2=%d\n", val1, val2);
		if (printf("%d ", i) < printf("%d ", j))
			printf("%d ", i);
		else
			printf("%d ", j);
//Here printf("%d", i) return 2 because it print 1 and newline i.e 2.
//And, printf("%d', j) return 3 because it print -1 and newline i.e number of character is 3.
//Therefore if statement look like if(2<3) yes its true.
//So if statement will execute. And answer is 1 -1 1.
	}
	{
		printf("\n");
		int s = 0;
		while (s++ < 10)
		{
			if (s < 4 && s < 9) continue;
			printf("%dt", s);
		}
	}
	{
		printf("\nStrings:\n");
		const char* s = "Hello";
		printf("\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);

		printf("Characters:\t%c %%\n", 65);

		printf("Integers\n");
		printf("Decimal:\t%i %d %.6i %i %.0i %+i %i\n", 1, 2, 3, 0, 0, 4, -4);
		printf("Hexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
		printf("Octal:\t%o %#o %#o\n", 10, 10, 4);

		printf("Floating point\n");
		printf("Rounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
		printf("Padding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
		printf("Scientific:\t%E %e\n", 1.5, 1.5);
		printf("Hexadecimal:\t%a %A\n", 1.5, 1.5);
		/*
Strings:
    .     Hello.
    .Hello     .
    .     Hello.
Characters:     A %
Integers
Decimal:        1 2 000003 0  +4 -4
Hexadecimal:    5 a A 0x6
Octal:          12 012 04
Floating point
Rounding:       1.500000 2 1.30000000000000004440892098500626
Padding:        01.50 1.50  1.50
Scientific:     1.500000E+00 1.500000e+00
Hexadecimal:    0x1.8p+0 0X1.8P+0
*/
	}

}