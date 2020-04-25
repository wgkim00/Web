#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
	char* publisher;	// 8		<-- multiple of 4
	int pub_year;		// 4
}Publisher;				// 16
typedef struct
{
	char title[30];		// 30		<-- multiple of 16
	Publisher pub;		// 16
} TEXTBOOK;				// 48

typedef struct
{
	char title[17];		// 21	17	21	<-- multiple of 4
	int pub;			// 4	4	0
} Test;					// 28	24	21

typedef struct
{							// size**
	char title[17];			// 21	17	<-- multiple of 8
	long long pub;			// 8	8
} Test2;					// 32	32

typedef struct
{							// size**	
	char title[21];			// 21	17	<-- multiple of 1
	char pub[7];			// 7	5
} Test3;					// 28	22

int main(void)
{
	TEXTBOOK my_book;
	my_book.pub.publisher = (char*)malloc(30);
	strcpy(my_book.pub.publisher, "Company1");

	TEXTBOOK* pbook = (TEXTBOOK*)malloc(sizeof(TEXTBOOK*));
	pbook->pub.publisher = (char*)malloc(30);
	strcpy(pbook->pub.publisher, "Company2");


	printf("%s %s\n", my_book.pub.publisher, pbook->pub.publisher);
	printf("TEXTBOOK=%d, Publisher=%d, pbook=%d\n",sizeof(TEXTBOOK), sizeof (Publisher), sizeof(pbook));
	printf("Test=%d, int=%d\n",sizeof(Test),sizeof(int));
	printf("Test2=%d, long long=%d\n", sizeof(Test2), sizeof(long long));
	printf("Test3=%d, long long=%d\n", sizeof(Test3), sizeof(long long));
	free(pbook->pub.publisher);
	free(pbook);
	free(my_book.pub.publisher);
	return 0;
}
