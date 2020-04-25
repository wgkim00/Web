// https://dojang.io/mod/page/view.php?id=456
// https://dojang.io/mod/page/view.php?id=455

// big & little endian
// union

#include <stdio.h>
#include <stdlib.h>
typedef union{
		char c1;
		short num1;
		int num2;
		char c8[8];
}UNION_ENDIAN;
#if 0
65 62 (hex)
101 98 (dec)
e b (ascii)
#endif

int main()
{
	UNION_ENDIAN a;
	char* str = "abcdefg";
	strcpy_s(a.c8, 8,str , sizeof(str));

	printf("c1:: %c\n", a.c1); // for big endian, \0
	printf("num1:: %c, %c\n", (char)a.num1, (char)(a.num1>>8));// for big endian, g \0
	printf("num2:: %c, %c, %c\n", (char)a.num2, (char)(a.num2 >> 8), (char)(a.num2 >> 16));

	UNION_ENDIAN b;
	b.num2 = 0x12345678;
	printf("c1:: %x\n", b.c1);// for big endian, 0x12
	printf("num1:: %x\n", b.num1);// for big endian, 0x1234
	printf("num2:: %x\n", b.num2);

	{
		//https://dojang.io/mod/page/view.php?id=494
		int* numPtr = malloc(sizeof(int));    // 4����Ʈ��ŭ �޸� �Ҵ�
		char* cPtr;

		*numPtr = 0x12345678;

		cPtr = (char*)numPtr;     // int ������ numPtr�� char �����ͷ� ��ȯ. �޸� �ּҸ� �����

		printf("0x%x\n", *cPtr);   // 0x78: ���� �ڸ��� 1����Ʈ�� �������Ƿ� 0x78

		free(numPtr);    // ���� �޸� ����
	}

}