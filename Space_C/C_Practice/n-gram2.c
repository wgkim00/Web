// https://dojang.io/mod/page/view.php?id=402

#include <stdio.h>
#include <string.h>

int main()
{
	char text[30];
	int length;
	int n = 4;	// N

	scanf("%s", text);

	length = strlen(text);
	if (length<n)
	{
		printf("wrong\n");
	}
	else
	{
		for (int i = 0; i< length-n+1; i++)
		{
			for (int j = 0; j<n; j++)
				printf("%c", text[i + j]);

			printf("\n");
		}
	}

	return 0;
}