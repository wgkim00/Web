#include <stdio.h>
#include <stdlib.h>

int main()
{
#if 1	// Even const variables can be changed!!!
	const int my1 = 10;
	int*  pmy1 = &my1;
	//my1 = 33;
	*pmy1 =100;
	printf("%3d %3d\n", *pmy1,my1);

	int my2 = 10;
	const int*  pmy2 = &my2;
	my2 = 33;
	//*pmy2 = 100;
	printf("%3d %3d\n", *pmy2, my2);

#endif

	char* t = malloc(10);
	strcpy(t, "12345678");
	for (int i = 0; i < strlen(t); i++)
	{
		printf("%c %p\n", t[i],&t[i]);
	}
	printf("\n");


	int* pArr = (int*)malloc(sizeof(int) * 3);
	for (int i = 0; i < 3; i++) pArr[i] = i * 10;
	for (int i = 0; i < 3; i++) printf("0:%2d %p\n", pArr[i], pArr+i);
	printf("\n");
	printf("sizeof(pointer)=%d\n", sizeof(int*));
	

	int Arr[3][4];
	printf("Arr:\n");
	printf("1:%d(%x)\n", sizeof(Arr), sizeof(Arr));
	for (int i = 0; i < 3; i++) printf("%p ", Arr + i); printf("\n");
	for (int i = 0; i < 3; i++) printf("%p ", &Arr[i]); printf("\n");
	for (int i = 0; i < 3; i++) printf("%p ", Arr[i]); printf("\n");


	printf("ppArr:\n");
	int** ppArr = (int**)malloc(sizeof(int*) * 3);
	printf("1:%x\n", ppArr);
	for (int i = 0; i < 3; i++) printf("%p ", ppArr + i); printf("\n");
	for (int i = 0; i < 3; i++) printf("%p ", &ppArr[i]); printf("\n");
	for (int i = 0; i < 3; i++) ppArr[i] = (int*)malloc(sizeof(int) * 4);
	for (int i = 0; i < 3; i++) printf("%p ", ppArr[i]); printf("\n");


	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			ppArr[i][j] = i + j;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%2d ", ppArr[i][j]);
		printf("\n");
	}

	// discontinuous addressing, different from array addressing
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%p ", *(ppArr+i)+j);
		printf("\n");
	}

	// can't get the row and column value, because ppArr is a pointer, not array
	printf("%d(%x)\n", sizeof(ppArr) / sizeof(ppArr[0]), sizeof(ppArr) / sizeof(ppArr[0]));

	for (int i = 0; i < 3; i++) free(ppArr[i]);
	free(ppArr);
	free(pArr);
}