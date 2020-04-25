// http://tcpschool.com/c/c_io_fileIOFunction
#if 0
stdio.h
1. int fgetc(FILE * stream);
2. int fputc(int c, FILE * stream);
3. char* fgets(char* restrict s, int n, FILE * restrict stream)
4. int fputs(const char* restrict s, FILE * restrict stream);
5. int fscanf(FILE * restrict stream, const char* restrict format, ...);
6. int fprintf(FILE * restrict stream, const char* restrict format, ...);

r read-only for text file
w write-only for txt file. if the file exits, it deletes contents and opens. if not exists, it makes a file.
wx write - only for txt file. 
파일을 쓰는 것만이 가능한 텍스트 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 파일 개방에 실패함.

a 파일을 쓰는 것만이 가능한 텍스트 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 해당 파일의 맨 끝에서부터 데이터를 추가함.

rb 파일을 오로지 읽는 것만 가능한 바이너리 모드로 개방함.

wb 파일을 쓰는 것만이 가능한 바이너리 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 해당 파일의 모든 데이터를 지우고 개방함.

wbx 파일을 쓰는 것만이 가능한 바이너리 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 파일 개방에 실패함.

ab 파일을 쓰는 것만이 가능한 바이너리 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 해당 파일의 맨 끝에서부터 데이터를 추가함.

r + 파일을 읽고 쓰는 것이 둘 다 가능한 텍스트 모드로 개방함.
w + 파일을 읽고 쓰는 것이 둘 다 가능한 텍스트 모드로 개방함. 
파일이 없으면 새 파일을 만들고, 파일이 있으면 해당 파일의 모든 데이터를 지우고 개방함.

w + x 파일을 읽고 쓰는 것이 둘 다 가능한 텍스트 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 파일 개방에 실패함.

a + 파일을 읽고 쓰는 것이 둘 다 가능한 텍스트 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 해당 파일의 맨 끝에서부터 데이터를 추가함.
읽기는 전체를 읽을 수 있지만, 쓰기는 파일의 맨 끝에만 추가할 수 있음.

r + b 또는 rb + 파일을 읽고 쓰는 것이 둘 다 가능한 바이너리 모드로 개방함.
w + b 또는 wb +
파일을 읽고 쓰는 것이 둘 다 가능한 바이너리 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 해당 파일의 모든 데이터를 지우고 개방함.

w + bx 또는 wb + x
파일을 읽고 쓰는 것이 둘 다 가능한 바이너리 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 파일 개방에 실패함.

a + b 또는 ab +
파일을 읽고 쓰는 것이 둘 다 가능한 바이너리 모드로 개방함.
파일이 없으면 새 파일을 만들고, 파일이 있으면 해당 파일의 맨 끝에서부터 데이터를 추가함.

#endif
#include<stdio.h>
#include <stdlib.h>

int main()
{
	FILE* pfile1=fopen("../txt/file_test.txt", "r");
	//FILE* pfile1 = fopen("../txt/mydata.csv", "r");
	FILE* pfile2 = fopen("../txt/file4write.txt", "w");
	if (!pfile1 )
	{
		system("cd");
		printf("pfile1! Something wrong!\n");
		return 0;
	}
	if (!pfile2)
	{
		system("cd");
		printf("pfile2! Something wrong!\n");
		return 0;
	}

	//  fgetc() 함수의 반환값은 다음과 같이 반드시 int형 변수로 저장해야 합니다.
	/*int c = fgetc(pfile1);
	while (c!=EOF)
	{
		fputc(c,stdout);
		c = fgetc(pfile1);
	}*/


	char arr[50] = { NULL, };
	while (fgets(arr, 50, pfile1))
	{
		fputs(arr, stdout);
		fputs(arr, pfile2);
	}

	fputs("\nFile copy done!", stdout);

	fclose(pfile2);
	fclose(pfile1);

	return 0;
}