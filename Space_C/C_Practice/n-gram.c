// https://dojang.io/mod/quiz/attempt.php?attempt=884749&cmid=403
// È¸¹®(palindrome)


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

#if 0 // From...
#if 0
	char Arr[31];
	scanf("%[^\n]s", Arr);

#else
	char Arr[31] = "nurs  es run";
#endif

	int len = strlen(Arr);
	int flag = 0;

	printf("sizeof(Arr)=%d, strlen=%d, %s\n", sizeof Arr, len, Arr);
	int j = 0;

	for (int i = 0; i < len / 2; i++)
	{
		while (Arr[i] == ' ') i++;
		while (Arr[len - j - 1] == ' ') j++;

		if (Arr[i] == Arr[len - j - 1]) flag = 1;
		else
		{
			flag = 0;
			break;
		}
		j++;
	}
#else// from

	char Arr[31] = "nurs  es run";
	int len = strlen(Arr);
	int flag = 1;
	int begin = 0;
	int end = strlen(Arr) - 1;

	while (begin < end)
	{
		while (Arr[begin] == ' ') begin++;
		while (Arr[end] == ' ') end--;

		if (Arr[begin] != Arr[end])
		{
			flag = 0;
			break;
		}
		begin++;
		end--;
	}

#endif// to
	printf("flag=%d\n", flag);



	char text[30] = "this is c language";
	char* tok[10] = { NULL, };

	int cnt = 0;
	char* wd = strtok(text, " ");
	while (wd)
	{
 		tok[cnt] = wd;
		++cnt;
		wd = strtok(NULL, " ");
	}
	for (int i = 0; i < cnt-1 ; i++)
	{
		printf("%s %s\n", tok[i], tok[i + 1]);
	}

	long long num1 = 123456787654321;
	char* str_num1 = (char*)malloc(100);
	sprintf(str_num1, "%lld", num1);					/**/
	len = strlen(str_num1);
	for (int i = 0; i < len / 2; i++)
	{
		if (str_num1[i] == str_num1[len - i - 1]) flag = 1;
		else
		{
			flag = 0;
			break;
		}
	}
	printf("num1=%lld, str=%s, flag=%d\n", num1, str_num1, flag);
	free(str_num1);
	return 0;
}