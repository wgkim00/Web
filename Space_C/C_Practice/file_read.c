// https://dojang.io/mod/page/view.php?id=610
// https://en.cppreference.com/w/c/io/rewind

#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // fopen, fgets, fclose 함수가 선언된 헤더 파일
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char str[20];

int main(void)
{
    FILE* f;
    char ch;

    f = fopen("file.txt", "w");
    for (ch = '0'; ch <= '9'; ch++) {
        fputc(ch, f);
    }
    fclose(f);

    f = fopen("..\\txt\\file_test.txt", "r");
    if (!f)
    {
        system("cd");
        printf("\npFile Wrong!\n");
        return 0;
    }
    fread(str, 1, 10, f);
    puts(str);

    rewind(f);
    fread(str, 1, 10, f);
    puts(str);


    fclose(f);

    {
        FILE* pFile;
        pFile = fopen("example.txt", "wb");
        fputs("1234567890abcdefghij1234567890", pFile);
        fseek(pFile, 9, SEEK_SET);
        fputs(" sam", pFile);
        fclose(pFile);

        pFile= fopen("example.txt", "rb");
        fseek(pFile, 0, SEEK_END);
        int size = ftell(pFile);
        printf("size=%d\n", size);

        char* buf = malloc(size + 1);
        memset(buf, 0, size + 1);

        //size_t ret_code = fread(buf, sizeof *buf, size-1, pFile);
        //fseek(pFile, 0, SEEK_SET);
        rewind(pFile);
        size_t ret_code = fread(buf, sizeof * buf, size, pFile);
        if(ret_code==size) printf("buf=%s\n", buf);
        else
        {
            if (feof(pFile))
                printf("Error reading test.bin: unexpected end of file\n");
            else if (ferror(pFile)) {
                perror("Error reading test.bin");
            }
        }

        fseek(pFile, 2, SEEK_SET);
        memset(buf, 0, size + 1);
        int pos = ftell(pFile);
        printf("[%d] pos=%d\n", __LINE__, pos);

        fread(buf, 1, 3, pFile);
        printf("%s\n", buf);

        pos = ftell(pFile);
        printf("[%d] pos=%d\n", __LINE__, pos);

        fseek(pFile, 10, SEEK_SET);
        memset(buf, 0, size + 1);

        pos = ftell(pFile);
        printf("[%d] pos=%d\n", __LINE__,pos);

        fread(buf, 5, 1, pFile);
        printf("%s\n", buf);

        pos = ftell(pFile);
        printf("[%d] pos=%d\n", __LINE__, pos);



        return 0;
    }
    if(0)
    {
        FILE* f1 = fopen("..\\txt\\file_test.txt", "r");
        fseek(f1, 0, SEEK_END);
        int count = ftell(f1);
        printf("size=%d\n", count);
        char* buf = (char*)malloc(sizeof(count) + 1);
        memset(buf, 0, sizeof(count) + 1);

        //fseek(f1, 0, SEEK_SET);
        //rewind(f1);

        if (fseek(f1, 0, SEEK_SET) != 0)
        {
            if (ferror(f1))
            {
                perror("fseek()");
                fprintf(stderr, "fseek() failed in file %s at line # %d\n", __FILE__, __LINE__ - 5);
                return;
            }
        }

        return 0;

        int ret=fread(buf, sizeof(char), count, f1);
        printf("ret=%d\n", ret);
        if (ret == count) printf("%s\n", buf);
        else printf("Wrong!\n");



        fclose(f1);
    }

    return 0;
}