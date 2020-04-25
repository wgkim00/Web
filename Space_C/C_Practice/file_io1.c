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
������ ���� �͸��� ������ �ؽ�Ʈ ���� ������.
������ ������ �� ������ �����, ������ ������ ���� ���濡 ������.

a ������ ���� �͸��� ������ �ؽ�Ʈ ���� ������.
������ ������ �� ������ �����, ������ ������ �ش� ������ �� ���������� �����͸� �߰���.

rb ������ ������ �д� �͸� ������ ���̳ʸ� ���� ������.

wb ������ ���� �͸��� ������ ���̳ʸ� ���� ������.
������ ������ �� ������ �����, ������ ������ �ش� ������ ��� �����͸� ����� ������.

wbx ������ ���� �͸��� ������ ���̳ʸ� ���� ������.
������ ������ �� ������ �����, ������ ������ ���� ���濡 ������.

ab ������ ���� �͸��� ������ ���̳ʸ� ���� ������.
������ ������ �� ������ �����, ������ ������ �ش� ������ �� ���������� �����͸� �߰���.

r + ������ �а� ���� ���� �� �� ������ �ؽ�Ʈ ���� ������.
w + ������ �а� ���� ���� �� �� ������ �ؽ�Ʈ ���� ������. 
������ ������ �� ������ �����, ������ ������ �ش� ������ ��� �����͸� ����� ������.

w + x ������ �а� ���� ���� �� �� ������ �ؽ�Ʈ ���� ������.
������ ������ �� ������ �����, ������ ������ ���� ���濡 ������.

a + ������ �а� ���� ���� �� �� ������ �ؽ�Ʈ ���� ������.
������ ������ �� ������ �����, ������ ������ �ش� ������ �� ���������� �����͸� �߰���.
�б�� ��ü�� ���� �� ������, ����� ������ �� ������ �߰��� �� ����.

r + b �Ǵ� rb + ������ �а� ���� ���� �� �� ������ ���̳ʸ� ���� ������.
w + b �Ǵ� wb +
������ �а� ���� ���� �� �� ������ ���̳ʸ� ���� ������.
������ ������ �� ������ �����, ������ ������ �ش� ������ ��� �����͸� ����� ������.

w + bx �Ǵ� wb + x
������ �а� ���� ���� �� �� ������ ���̳ʸ� ���� ������.
������ ������ �� ������ �����, ������ ������ ���� ���濡 ������.

a + b �Ǵ� ab +
������ �а� ���� ���� �� �� ������ ���̳ʸ� ���� ������.
������ ������ �� ������ �����, ������ ������ �ش� ������ �� ���������� �����͸� �߰���.

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

	//  fgetc() �Լ��� ��ȯ���� ������ ���� �ݵ�� int�� ������ �����ؾ� �մϴ�.
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