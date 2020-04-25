#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


typedef struct {
	char* publisher;	// 8
	int pub_year;		// 4
}Publisher;				// 16
typedef struct
{
	char title[30];		// 30 	// 30	//30
	char author[30];	// 30 	// 30	//30
	int price;			// 4	// 4	// 0
	char* temp;			// 8	// 8	//8
	Publisher pub;		// 16	// 0	// 0
} TEXTBOOK;				// 88?	// 72?	// 72


typedef struct
{
	char title[30];	//30
	char author[30];//30
	char* temp;		//8
} TEXTBOOK_88;		//72


typedef struct
{
	char titile[17];
} Struct_17;
typedef struct
{
	char title[31];		// 31->32 	0		0		31		31
	char author[31];	// 31->32 	32		0		31		0
	int price;			// 4->8		4		4		0		0
	char* temp;			// 8		8		8		0		0
	Struct_17 pub;		// 17->24	17		17		17		17
} StrTemp;				// 104		64		40		79(?)	48(!)


typedef struct
{
	int titile[2];
} Struct_8;
typedef struct
{
	char title[31];		//31
	char author[31];	
	int price;		//4
	char* temp;			//8
	Struct_8 pub;		//8
} StrTemp_8;			//56

typedef struct
{
	// int->pointer->int = 24, int->int->pointer = 16
	int a;		// 4
	char* b;	// 8
	int c;		// 4
}StructSize;	// 24 or 16

int main(void)
{
	printf("pointer=%d, Struct_8=%d, StrTemp_8=%d\n", sizeof(char*),sizeof(Struct_8), sizeof(StrTemp_8));
	printf("TEXTBOOK_88=%d, StructSize=%d\n", sizeof(TEXTBOOK_88), sizeof(StructSize));
	printf("Struct_17=%d, StrTemp=%d\n", sizeof(Struct_17), sizeof(StrTemp));
	printf("Publisher=%d, TEXTBOOK=%d\n", sizeof(Publisher), sizeof(TEXTBOOK));
	//  Publisher=16, TEXTBOOK=88

#if 0
	TEXTBOOK my_book = { "HTML과 CSS", "홍길동", 28000 };
	my_book.temp = (char*)malloc(20);
	my_book.pub.publisher = (char*)malloc(30);
	strcpy(my_book.pub.publisher, "Auckland Pub.");
	my_book.pub.pub_year = 2001;


	strcpy(my_book.temp, "Shakespeare");
	printf("%s\n", my_book.temp);

	TEXTBOOK java_book = { .title = "Java language", .price = 30000 };
	TEXTBOOK* pbook =  (TEXTBOOK*)malloc(sizeof (TEXTBOOK));
	pbook->pub.publisher = (char*)malloc(sizeof(char)*20);
	pbook->temp = (int*)malloc(sizeof(char) *20);
#if 1
	//memcpy(pbook->pub.publisher, my_book.pub.publisher,30);
	strcpy(pbook->pub.publisher, "Milford");
	memcpy(pbook->title, my_book.title,sizeof(char)*30);
	memcpy(pbook->temp, my_book.temp,20);
	printf("%s\n", (*pbook).temp);
	printf("title= %s이고, author= %s이며, price= %d원입니다.\n", my_book.title, my_book.author, my_book.price);
	printf("second title= %s이고, 저자는 %s이며, 가격은 %d원입니다.\n", java_book.title, java_book.author, java_book.price);
//	printf("pub= %s이고, year=%d \n", my_book.pub.publisher, my_book.pub.pub_year);
//	printf("pub= %s이고, year=%d \n", pbook->pub.publisher, pbook->pub.pub_year);
#endif

	free(pbook->temp);
	free(pbook->pub.publisher);
	free(pbook);
	free(my_book.pub.publisher);
	free(my_book.temp);

#endif


	return 0;
}
