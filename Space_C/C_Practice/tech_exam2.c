#include <stdio.h>

void main()
{
	{
		// The default case can be placed anywhere inside the loop. 
		// It is executed only when all other cases doesn't match.
		int i = 0;
		// three in case of i=3, zeroone in case that i is not between 1 and 3
		switch (i)
		{
		default: printf("zero");
		case 1: printf("one"); break;
		case 2: printf("two"); break;
		case 3: printf("three"); break;
		}
	}
#if 0
	{
		// Since static variables are initialized to zero by default.
		// C compiler makes error, but C++ compiler makes on error
		// error: initializer element is not constant
		static int i = i++, j = j++, k = k++;
		printf("%d %d %d", i, j, k);
	}
#endif

#if 0
	{
#if 0
	Compiler error : lvalue required Error is in line with statement a++.
	The operand must be an lvalue and may be of any of scalar type for any operator, array name only when subscripted is an lvalue.
	Simply array name is a non - modifiable lvalue.
#endif
		int a[] = { 10,20,30,40,50 }, j, * p;
		for (j = 0; j < 5; j++) {
			printf("%d", *a);
			a++;		//  error C2105: '++' needs l-value
		}
		p = a;
		for (j = 0; j < 5; j++) {
			printf("%d", *p);
			p++;
		}
	}
#endif
	{
	/* Before entering into the for loop checking condition is "evaluated". 
	Here it evaluates to 0 (false) and comes out of the loop, 
	and i is incremented (note the semicolon after the for loop).*/
		int i = 0;
		for (; i++; printf("---------"));
		printf("%d", i);	// 1
	}
	{
		int i = -1;
		+i;
		printf("i = %d, +i = %d\n", i, +i);	//  i = -1, +i = -1
	}
#if 0
	{
		//p is a pointer to a "constant integer". 
		// But we tried to change the value of the "constant integer".
		int const* p = 5;
		printf("%d", ++(*p));
	}
#endif
	{
		int i = 5;
		int const* p = &i;
		i = 10;
		printf("%d", *p);
	}
	{
		int c[] = { 2.8,3.4,4,6.7,5 };
		int j, * p = c, * q = c;
		for (j = 0; j < 5; j++) {
			printf(" %d ", *c);	// 2 2 2 2 2
			++q;
		}
		for (j = 0; j < 5; j++) {
			printf(" %d ", *p);	// 2 3 4 6 5
			++p;
		}
		printf("\n");
	}
#if 0
	{
		/* scanf returns number of items successfully read and not 1/0. 
		Here 10 is given as input which should have been scanned successfully. 
		So number of items read is 1.
		*/
		int i;
		printf("%d", scanf("%d", &i)); // value 10 is given as input here
	}
#endif
	{
		if (sizeof(int) > -1)// sizeof의 반환형이 size_t이고, 이것은 
			printf("True");
		else
			printf("False");/********/
	}
}
