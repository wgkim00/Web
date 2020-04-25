// https://dojang.io/mod/page/view.php?id=401

#include <stdio.h>
#include <string.h>

int main()
{
	long long num;

	scanf("%lld", &num);
	char arr[30];
	sprintf(arr, "%lld", num);
	int len = strlen(arr);
	int flag = 1;

	for( int i=0; i< len/2;i++)
		if (arr[i] != arr[len - i - 1])
		{
			flag = 0;
			break;
		}
	printf("flag=%d\n", flag);
	flag = 1;

	int begin = 0;
	int end = len - 1;
	while (begin < end)
	{
		if (arr[begin] != arr[end])
		{
			flag = 0;
			break;
		}
		begin++;
		end--;
	}
	printf("flag=%d\n", flag);

	return 0;	
}