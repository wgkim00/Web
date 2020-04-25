


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int b = 11;

void fn1(int** ppa)
{
	*ppa = &b;
}
void fn2(int** ppa)
{
	*ppa = &b;
}
int main()
{
	char str01[] = "10";
	char str02[] = "20";
	const char str03[] = "-34.123f";

	//double str03 = atof((const char*)str03);
	printf("%.3f\n", atof(str03));


#if 1
	// https://dojang.io/mod/page/view.php?id=400
#define _POINT01_
#ifdef _POINT01_
	char* str04 = malloc(sizeof(char) * 100);
	strcpy(str04, "This is my house at Milford.");
#else
	char str04[100] = "This is my house at Milford.";
#endif
	char* pArr04[10] = { NULL, };
	int num = 0;

	char* ptr04 = strtok(str04, " ");
	while (ptr04)
	{
		pArr04[num] = ptr04;
		ptr04 = strtok(NULL, " ");
		if (ptr04) num++;
	}
	for (int i = 0; i < num; i++)
		printf("%s %s\n", pArr04[i], pArr04[i + 1]);
#ifdef _POINT01_
	free(str04);
#endif
#endif


#if 1
	printf("sizeof(int)=%d\n", sizeof(int));
	int* arr[5];
	printf("sizeof(arr)=%d, sizeof(arr[0])=%d\n", sizeof(arr), sizeof(arr[0]));
	int aaa[3][5];
	printf("sizeof(aaa)=%d, sizeof(aaa[0])=%d\n", sizeof(aaa), sizeof(aaa[0]));
	int(*pArr)[5] = aaa;
	printf("sizeof(pArr)=%d, sizeof(pArr[0])=%d\n", sizeof(pArr), sizeof(pArr[0]));
	printf("&pArr=%p, pArr=%p, pArr[0]=%p\n", &pArr, pArr, pArr[0]);
	printf("&aaa=%p, aaa=%p, aaa[0]=%p\n", &aaa, aaa, aaa[0]);
	printf("&aaa+1=%p, aaa+1=%p, &pArr+1=%p, pArr+1=%p\n", &aaa+1, aaa + 1, &pArr + 1, pArr + 1);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++) printf("%p ", &aaa[i][j]);
		printf("\n");
	}
/*
sizeof(int)=4
sizeof(arr)=40, sizeof(arr[0])=8
sizeof(aaa)=60, sizeof(aaa[0])=20
sizeof(pArr)=8, sizeof(pArr[0])=20
&pArr=00000041A48FF928, pArr=00000041A48FF8C8, pArr[0]=00000041A48FF8C8
&aaa=00000041A48FF8C8, aaa=00000041A48FF8C8, aaa[0]=00000041A48FF8C8
&aaa+1=00000041A48FF904, aaa+1=00000041A48FF8DC, &pArr+1=00000041A48FF930, pArr+1=00000041A48FF8DC
*/
#endif




	int a = 10;
	int* pa = &a;
	int** ppa = &pa;

	fn1(&pa);
	printf("[%d] a=%d, *pa=%d\n", __LINE__, a, *pa);

	pa = &a;
	fn2(ppa);
	printf("[%d] a=%d, *pa=%d\n", __LINE__, a, *pa);

	return 0;
}