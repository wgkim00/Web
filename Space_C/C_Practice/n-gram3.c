// https://dojang.io/mod/quiz/attempt.php?attempt=885793&cmid=404

#include <stdio.h>
#include <string.h>


int main()
{
	int n;			/* n-gram */
	char arr[11];
	scanf("%d %11s", &n, arr);	// 4 Totaravale

	//printf("n=%d, arr=%s\n", n, arr);

	int len = strlen(arr);
	if (len < n) printf("wrong");

	for (int i = 0; i < len - n+1; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%c", arr[i+j]);
		printf("\n");
	}

	return 0;
}