// https://www.examveda.com/c-program/practice-mcq-question-on-c-miscellaneous
#include <stdio.h>


void fun()
{
HERE:
	printf("HERE\n");
}

int main()
{
	{
		printf("\nab");
		printf("\bsi");
		printf("\rha");
/*  answer: hai
\n - newline - printf("\nab"); - Prints ab
\b - backspace - printf("\bsi"); - firstly '\b' removes 'b' from 'ab ' 
and then prints 'si'. So after execution of printf
\r - back at the beginning of the current line
write ha : overrides the first two characters (producing hai on the second line)
*/
	}
	{
		int i = 10;
		i = !i>14;
		printf("\ni=%d\n", i);
/*		<<unary opratiors have higher precedence than binary oprators>>
In the expression !i>14 , NOT (!) operator has more precedence than ">" symbol. 
! is a unary logical operator. !i (!10) is 0 (not of true is false). 
0>14 is false (zero).
*/
	}
	{
		int c = -      -        2;
		printf("c=%d\n", c);
/*
Here unary minus (or negation) operator is used twice. It doesn't matter if it include spaces
Same maths rule applies, ie. minus * minus= plus.
Note: However you cannot give like --2. 
Because -- operator can only be applied to variables as a decrement operator (eg., i--). 2 is a constant and not a variable.
*/
	}
	{
		int i = 2;
		switch (i)
		{
		default: printf("Default\n");
		case 1: printf("One\n"); break;
		case 2: printf("Two\n"); break;
		}
/*
The default case can be placed anywhere inside the loop. 
It is executed only when all other cases doesn't match.
*/
	}
	{
		int i = 5;
		printf("%d%d%d%d%d\n", i++, i--, ++i, --i, i);
/*     45545
The arguments in a function call are pushed into the stack from left to right. 
The evaluation is by popping out from the stack. 
and the evaluation is from right to left, hence the result. See the picture below
*/
	}
	{
		char p[20] = "hi friends", * p1;
		p1 = p;
		while (*p1 != '\0') ++*p1++;
		printf("%s\n", p);
	/*    ij!gsjfoet
p가 array이면, string을 변경할 수 있지만, 
p가 pointer이면 constant literal을 변경할 수 없다.(runtime error)
https://www.examveda.com/determine-output-c-programming-miscellanneous-14/#commentAdd
	*/
	}
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

	//{
	//	goto HERE;
	//}

	if(0)
	{
		int i, j;
		int ret1, ret2;
		ret1 = scanf("          %d          ", &i);
		ret2 = scanf("   ,       %d          ", &j);
		printf("ret1=%d, ret2=%d, i=%d, j=%d\n", ret1, ret2,i,j);
	}

	{
		int i = 0;
		for (; i++; printf("i=%d*", i));
		printf("i=%d\n", i);
/*		i=1
Before entering into the for loop checking condition is "evaluated". 
Here it evaluates to 0 (false) and comes out of the loop, and i is incremented 
(note the semicolon after the for loop).
*/
	}
	/* error LNK2001: unresolved external symbol i
	{
		extern int i;
		i = 20;
		printf("i=%d\n", i);

	}*/

#if 0
	void main()
	{
		static int i = 5;
		// 4 3 2 1 (0) i가 0이 되면, if 실행안됨. 따라서, 4개의 0이 출력됨.
		if (--i) {
			main();
			printf("%d ", i);
		}
	}
	The variable "i" is declared as static, hence memory for I will be allocated for only once,
	as it encounters the statement.The function main() will be called recursively 
		unless I becomes equal to 0, and since main() is recursively called, 
		so the value of static I ie., 0 will be printed every time the control is returned.
#endif
	{
		char* str1 = "abcd";
		char str2[] = "abcd";
		printf("sizeof(str1)=%d, sizeof(str2)=%d, sizeof(\"abcd\")=%d\n",
			sizeof(str1), sizeof(str2), sizeof("abcd"));
	}
	{
		int i = 5, j = 6;
		printf("i+++j=%d\n",i+++j);
	}
	{
		char p[] = "%d\n";
		p[1] = 'c';
		printf(p, 65);
		printf("sizeof(p)=%d, strlen(p)=%d\n", sizeof p, strlen(p));
		printf("sizeof(\"%%d\\n\")=%d, strlen(\"%%d\\n\")=%d\n", sizeof "%d\n", strlen("%d\n"));
		for (int i = 0; i < strlen(p); i++)
			printf("%c,", p[i]);
		printf("\n");
	}
	{
		int a[] = { 10,20,30,40,50 };
		int* p;
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", *a);
			//a++;    //<-- error C2105: '++' needs l-value
		}
	}
	{
		static char* s[] = { "black", "white","yellow","violet" };
		char** ptr[] = { s + 3, s + 2, s + 1, s }, *** p;
		p = ptr;
		++p;
		printf("%s", *--*++p+3);		// answer: ck
/*
In this problem we have an array of char pointers "s" pointing to start of 4 strings. 
Then we have ptr which is a pointer to a pointer of type char and a variable p 
which is a pointer to a pointer to a pointer of type char. p holds the initial value of ptr, 
i.e. p = s+3. The next statement increment value in p by 1 , thus now value of p = s+2. 
In the printf statement the expression is evaluated as follows: 
*++p causes gets value s+1 then the pre decrement is executed and we get s+1-1 = s 
which is pointing to the word "black". The indirection operator now gets the value 
from the array of s and adds 3 to the starting address. The string is printed starting 
from this position. Thus, the output is 'ck'.
*/
	}
	return 0;
}
