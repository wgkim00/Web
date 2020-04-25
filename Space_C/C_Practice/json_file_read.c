// https://dojang.io/mod/page/view.php?id=722
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "json.h"

/*
���⼭�� �ε����� ������ ����, ���ڿ� �Լ��� Ȱ���Ͽ� ���ڿ��� �м��ϴ� ���� ���� �߿��� �κ��Դϴ�.
���ذ� �� ���� �ʴ´ٸ� 
'Unit 39 ���ڿ� ����ϱ�', 
'Unit 44 ���ڿ� �˻��ϱ�', 
'Unit 59 ������ ���� ����ϱ�'�� �����ϴ� ���� �����ϴ�.
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
		case '[':        // ���ڰ� [�̸� �迭
		{
			pos++;       // ���� ���ڷ�

			while (doc[pos] != ']')    // �ݴ� ]�� ������ �ݺ� ����
			{
				// ���⼭�� ���ڿ� �迭�� ó��
				if (doc[pos] == '"')   // ���ڰ� "�̸� ���ڿ�
				{
					// ���ڿ��� ���� ��ġ�� ����. �� ���� "�� �����ϱ� ���� + 1
					char* begin = doc + pos + 1;

					// ���ڿ��� �� ��ġ�� ����. ���� "�� ��ġ
					char* end = strchr(begin, '"');
					if (end == NULL)   // "�� ������ �߸��� �����̹Ƿ�
						break;         // �ݺ��� ����

					int stringLength = end - begin;    // ���ڿ��� ���� ���̴� �� ��ġ - ���� ��ġ

					// ��ū �迭�� ���ڿ� ����
					// ��ū ������ ���ڿ�
					json->tokens[tokenIndex].type = TOKEN_STRING;
					// ���ڿ� ���� + NULL ������ŭ �޸� �Ҵ�
					json->tokens[tokenIndex].string = malloc(stringLength + 1);
					// ���� ���ڿ��� �迭�� ���
					json->tokens[tokenIndex].isArray = true;
					// �Ҵ��� �޸𸮸� 0���� �ʱ�ȭ
					memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

					// �������� ���ڿ��� ��ū�� ����
					// ���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����
					memcpy(json->tokens[tokenIndex].string, begin, stringLength);

					tokenIndex++; // ��ū �ε��� ����

					pos = pos + stringLength + 1; // ���� ��ġ + ���ڿ� ���� + "(+ 1)
				}

				pos++;    // ���� ���ڷ�
			}
		}
		break;
		case '0': case '1': case '2': case '3': case '4': case '5':    // ���ڰ� �����̸�
		case '6': case '7': case '8': case '9': case '-':  case '.':          // -�� ������ ��
		{
			// ���ڿ��� ���� ��ġ�� ����
			char* begin = doc + pos;
			char* end;
			char* buffer;

			// ���ڿ��� �� ��ġ�� ����. ,�� �����ų�
			end = strchr(doc + pos, ',');
			if (end == NULL)
			{
				// } �� ������ ���ڿ��� ����
				end = strchr(doc + pos, '}');
				if (end == NULL)    // }�� ������ �߸��� �����̹Ƿ�
					break;          // �ݺ��� ����
			}

			int stringLength = end - begin;    // ���ڿ��� ���� ���̴� �� ��ġ - ���� ��ġ

			// ���ڿ� ���� + NULL ������ŭ �޸� �Ҵ�
			buffer = malloc(stringLength + 1);
			// �Ҵ��� �޸𸮸� 0���� �ʱ�ȭ
			memset(buffer, 0, stringLength + 1);

			// �������� ���ڿ��� ���ۿ� ����
			// ���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����
			memcpy(buffer, begin, stringLength);

			// ��ū ������ ����
			json->tokens[tokenIndex].type = TOKEN_NUMBER;
			// ���ڿ��� ���ڷ� ��ȯ�Ͽ� ��ū�� ����
			json->tokens[tokenIndex].number = atof(buffer);

			free(buffer);    // ���� ����

			tokenIndex++;    // ��ū �ε��� ����

			pos = pos + stringLength + 1;    // ���� ��ġ + ���ڿ� ���� + , �Ǵ� }(+ 1)
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

// Ű�� �ش��ϴ� ���ڿ��� �������� �Լ�
char* getString(JSON* json, char* key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)    // ��ū ������ŭ �ݺ�
	{
		// ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�ϸ�
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// �ٷ� ���� ��ū(i + 1)�� ���ڿ��̸�
			if (json->tokens[i + 1].type == TOKEN_STRING)
				return json->tokens[i + 1].string;    // �ٷ� �ڿ� �ִ� ��ū�� ���ڿ� ��ȯ
		}
	}

	return NULL;    // Ű�� ã�� �������� NULL�� ��ȯ
}
// Ű�� �ش��ϴ� �迭 �� �ε����� �����Ͽ� ���ڿ��� �������� �Լ�
char* getArrayString(JSON* json, char* key, int index)
{
	for (int i = 0; i < TOKEN_COUNT; i++)    // ��ū ������ŭ �ݺ�
	{
		// ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�Ѵٸ�
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// �ٷ� ���� ��ū(i + 1)���� �迭�� ���
			// �ε����� ������ ��ū�� ���ڿ��̸鼭 �迭�̸�
			if (json->tokens[i + 1 + index].type == TOKEN_STRING &&
				json->tokens[i + 1 + index].isArray == true)
				return json->tokens[i + 1 + index].string;    // �ش� ��ū�� ���ڿ� ��ȯ
		}
	}

	return NULL;    // Ű�� ã�� �������� NULL�� ��ȯ
}

// Ű�� �ش��ϴ� �迭�� ��� ������ ���ϴ� �Լ�
int getArrayCount(JSON* json, char* key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)    // ��ū ������ŭ �ݺ�
	{
		// ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�Ѵٸ�
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// �ٷ� ���� ��ū(i + 1)���� isArray�� true�� ��ū�� ������ ��� ��ȯ
			int j = 0;
			while (json->tokens[i + 1 + j].isArray == true)
				j++;

			return j;
		}
	}

	return 0;    // Ű�� ã�� �������� 0�� ��ȯ
}

// Ű�� �ش��ϴ� ���ڸ� �������� �Լ�
double getNumber(JSON* json, char* key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)    // ��ū ������ŭ �ݺ�
	{
		// ��ū ������ �����̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�Ѵٸ�
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// �ٷ� ���� ��ū(i + 1)�� �����̸�
			if (json->tokens[i + 1].type == TOKEN_NUMBER)
				return json->tokens[i + 1].number;    // �ٷ� �ڿ� �ִ� ��ū�� ���� ��ȯ
		}
	}

	return 0.0;    // Ű�� ã�� �������� 0.0�� ��ȯ
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


	printf("Title: %s\n", getString(json, "Title"));           // Title�� �� ���
	printf("Year: %d\n", (int)getNumber(json, "Year"));        // Year�� �� ���
	printf("Runtime: %d\n", (int)getNumber(json, "Runtime"));  // Runtime�� �� ���
	printf("Genre: %s\n", getString(json, "Genre"));           // Genre�� �� ���
	printf("Director: %s\n", getString(json, "Director"));     // Director�� �� ���

	printf("Actors:\n");
	int actors = getArrayCount(json, "Actors");                // Actors �迭�� ������ ����
	for (int i = 0; i < actors; i++)                            // �迭�� ��� ������ŭ �ݺ�
		printf("  %s\n", getArrayString(json, "Actors", i));   // �ε����� �����Ͽ� ���ڿ��� ������

	printf("imdbRating: %f\n", getNumber(json, "imdbRating")); // imdbRating�� �� ���


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
		char* s1 = malloc(sizeof(char) * 30);    // char 30�� ũ�⸸ŭ ���� �޸� �Ҵ�

		sprintf(s1, "%c %d %f %e", 'a', 10, 3.2f, 1.123456e-21f);    // ����, ����, �Ǽ��� ���ڿ��� ����

		printf("%s\n", s1);    // a 10 3.200000 1.123456e-21: ���ڿ� s1 ���

		free(s1);    // ���� �޸� ����

	}
}