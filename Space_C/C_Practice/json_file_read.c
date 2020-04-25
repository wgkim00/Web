// https://dojang.io/mod/page/view.php?id=722
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "json.h"

/*
여기서는 인덱스와 포인터 연산, 문자열 함수를 활용하여 문자열을 분석하는 것이 가장 중요한 부분입니다.
이해가 잘 되지 않는다면 
'Unit 39 문자열 사용하기', 
'Unit 44 문자열 검색하기', 
'Unit 59 포인터 연산 사용하기'를 복습하는 것이 좋습니다.
*/
char* readFile(char* filename, int* filesize)
{
	FILE* fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		*filesize = 0;
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	rewind(fp);
	*filesize = size;
	char* buf = malloc(size + 1);
	memset(buf, 0, size + 1);
	fread(buf, size, 1, fp);

	fclose(fp);
	return buf;
}

void parseJSON(char* doc, int size, JSON* json)
{
	int pos = 0;

	if (doc[pos] != '{') return;
	char* begin = NULL;
	char* end = NULL;
	int tokenIndex = 0;
	while (pos < size)
	{
		switch (doc[pos])
		{
		case '"':
			begin = doc + pos+1;
			end = strchr(begin, '"');
			if (end == NULL) return;
			int strlength = end - begin;

			json->tokens[tokenIndex].type = TOKEN_STRING;
			json->tokens[tokenIndex].string = malloc(strlength +1);
			memset(json->tokens[tokenIndex].string, 0, strlength + 1);
			memcpy(json->tokens[tokenIndex].string, begin, strlength);
			++tokenIndex;
			pos = pos + strlength + 1;
			break;
		case '[':        // 문자가 [이면 배열
		{
			pos++;       // 다음 문자로

			while (doc[pos] != ']')    // 닫는 ]가 나오면 반복 종료
			{
				// 여기서는 문자열 배열만 처리
				if (doc[pos] == '"')   // 문자가 "이면 문자열
				{
					// 문자열의 시작 위치를 구함. 맨 앞의 "를 제외하기 위해 + 1
					char* begin = doc + pos + 1;

					// 문자열의 끝 위치를 구함. 다음 "의 위치
					char* end = strchr(begin, '"');
					if (end == NULL)   // "가 없으면 잘못된 문법이므로
						break;         // 반복을 종료

					int stringLength = end - begin;    // 문자열의 실제 길이는 끝 위치 - 시작 위치

					// 토큰 배열에 문자열 저장
					// 토큰 종류는 문자열
					json->tokens[tokenIndex].type = TOKEN_STRING;
					// 문자열 길이 + NULL 공간만큼 메모리 할당
					json->tokens[tokenIndex].string = malloc(stringLength + 1);
					// 현재 문자열은 배열의 요소
					json->tokens[tokenIndex].isArray = true;
					// 할당한 메모리를 0으로 초기화
					memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

					// 문서에서 문자열을 토큰에 저장
					// 문자열 시작 위치에서 문자열 길이만큼만 복사
					memcpy(json->tokens[tokenIndex].string, begin, stringLength);

					tokenIndex++; // 토큰 인덱스 증가

					pos = pos + stringLength + 1; // 현재 위치 + 문자열 길이 + "(+ 1)
				}

				pos++;    // 다음 문자로
			}
		}
		break;
		case '0': case '1': case '2': case '3': case '4': case '5':    // 문자가 숫자이면
		case '6': case '7': case '8': case '9': case '-':  case '.':          // -는 음수일 때
		{
			// 문자열의 시작 위치를 구함
			char* begin = doc + pos;
			char* end;
			char* buffer;

			// 문자열의 끝 위치를 구함. ,가 나오거나
			end = strchr(doc + pos, ',');
			if (end == NULL)
			{
				// } 가 나오면 문자열이 끝남
				end = strchr(doc + pos, '}');
				if (end == NULL)    // }가 없으면 잘못된 문법이므로
					break;          // 반복을 종료
			}

			int stringLength = end - begin;    // 문자열의 실제 길이는 끝 위치 - 시작 위치

			// 문자열 길이 + NULL 공간만큼 메모리 할당
			buffer = malloc(stringLength + 1);
			// 할당한 메모리를 0으로 초기화
			memset(buffer, 0, stringLength + 1);

			// 문서에서 문자열을 버퍼에 저장
			// 문자열 시작 위치에서 문자열 길이만큼만 복사
			memcpy(buffer, begin, stringLength);

			// 토큰 종류는 숫자
			json->tokens[tokenIndex].type = TOKEN_NUMBER;
			// 문자열을 숫자로 변환하여 토큰에 저장
			json->tokens[tokenIndex].number = atof(buffer);

			free(buffer);    // 버퍼 해제

			tokenIndex++;    // 토큰 인덱스 증가

			pos = pos + stringLength + 1;    // 현재 위치 + 문자열 길이 + , 또는 }(+ 1)
		}
		break;
		}
		++pos;
	}

	printf("tokenIndex=%d\n", tokenIndex);
}

void freeJSON(JSON* json)
{
	for (int i = 0; i < TOKEN_COUNT; ++i)
	{
		if (json->tokens[i].type == TOKEN_STRING
			&& json->tokens[i].string != NULL)
			free(json->tokens[i].string);
	}
	free(json);
}

// 키에 해당하는 문자열을 가져오는 함수
char* getString(JSON* json, char* key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)    // 토큰 개수만큼 반복
	{
		// 토큰 종류가 문자열이면서 토큰의 문자열이 키와 일치하면
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// 바로 뒤의 토큰(i + 1)이 문자열이면
			if (json->tokens[i + 1].type == TOKEN_STRING)
				return json->tokens[i + 1].string;    // 바로 뒤에 있는 토큰의 문자열 반환
		}
	}

	return NULL;    // 키를 찾지 못했으면 NULL을 반환
}
// 키에 해당하는 배열 중 인덱스를 지정하여 문자열을 가져오는 함수
char* getArrayString(JSON* json, char* key, int index)
{
	for (int i = 0; i < TOKEN_COUNT; i++)    // 토큰 개수만큼 반복
	{
		// 토큰 종류가 문자열이면서 토큰의 문자열이 키와 일치한다면
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// 바로 뒤의 토큰(i + 1)부터 배열의 요소
			// 인덱스를 지정한 토큰이 문자열이면서 배열이면
			if (json->tokens[i + 1 + index].type == TOKEN_STRING &&
				json->tokens[i + 1 + index].isArray == true)
				return json->tokens[i + 1 + index].string;    // 해당 토큰의 문자열 반환
		}
	}

	return NULL;    // 키를 찾지 못했으면 NULL을 반환
}

// 키에 해당하는 배열의 요소 개수를 구하는 함수
int getArrayCount(JSON* json, char* key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)    // 토큰 개수만큼 반복
	{
		// 토큰 종류가 문자열이면서 토큰의 문자열이 키와 일치한다면
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// 바로 뒤의 토큰(i + 1)부터 isArray가 true인 토큰의 개수를 세어서 반환
			int j = 0;
			while (json->tokens[i + 1 + j].isArray == true)
				j++;

			return j;
		}
	}

	return 0;    // 키를 찾지 못했으면 0을 반환
}

// 키에 해당하는 숫자를 가져오는 함수
double getNumber(JSON* json, char* key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)    // 토큰 개수만큼 반복
	{
		// 토큰 종류가 숫자이면서 토큰의 문자열이 키와 일치한다면
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// 바로 뒤의 토큰(i + 1)이 숫자이면
			if (json->tokens[i + 1].type == TOKEN_NUMBER)
				return json->tokens[i + 1].number;    // 바로 뒤에 있는 토큰의 숫자 반환
		}
	}

	return 0.0;    // 키를 찾지 못했으면 0.0을 반환
}
int main()
{
	int filesize = 0;
	char filename[20] = "example.json";
	char* buff = readFile(filename, &filesize);
	if (buff == NULL) return -1;
	printf("filesize=%d\n", filesize);

	JSON* json=malloc(sizeof(JSON));
	memset(json, 0, sizeof(JSON));

	parseJSON(buff, filesize, json);


	printf("Title: %s\n", getString(json, "Title"));           // Title의 값 출력
	printf("Year: %d\n", (int)getNumber(json, "Year"));        // Year의 값 출력
	printf("Runtime: %d\n", (int)getNumber(json, "Runtime"));  // Runtime의 값 출력
	printf("Genre: %s\n", getString(json, "Genre"));           // Genre의 값 출력
	printf("Director: %s\n", getString(json, "Director"));     // Director의 값 출력

	printf("Actors:\n");
	int actors = getArrayCount(json, "Actors");                // Actors 배열의 개수를 구함
	for (int i = 0; i < actors; i++)                            // 배열의 요소 개수만큼 반복
		printf("  %s\n", getArrayString(json, "Actors", i));   // 인덱스를 지정하여 문자열을 가져옴

	printf("imdbRating: %f\n", getNumber(json, "imdbRating")); // imdbRating의 값 출력


	for (int i = 0; i < TOKEN_COUNT; ++i)
	{
		if (json->tokens[i].type == TOKEN_STRING
			&& json->tokens[i].string != NULL)
			printf("[%d] %s\n", i, json->tokens[i].string);
		else if (json->tokens[i].type == TOKEN_NUMBER)
			printf("[%d] %.1f\n", i, json->tokens[i].number);
	}



	freeJSON(json);
	free(buff);

	{
		char* s1 = malloc(sizeof(char) * 30);    // char 30개 크기만큼 동적 메모리 할당

		sprintf(s1, "%c %d %f %e", 'a', 10, 3.2f, 1.123456e-21f);    // 문자, 정수, 실수를 문자열로 만듦

		printf("%s\n", s1);    // a 10 3.200000 1.123456e-21: 문자열 s1 출력

		free(s1);    // 동적 메모리 해제

	}
}