//http://tcpschool.com/c/c_io_console

#include <stdio.h>

int main(void)
{
	char str[20] = { NULL, };
	char ch;

	puts("����� �̸��� �����ּ��� : ");
#if 0
	// ����ڰ� �̸��� �Է��� �� ������, ������ �Է����� ���ϰ� ���α׷��� ����˴ϴ�.
	// �� ������ �̸��� �Է¹��� �� ���������� �Է��� ����(Enter) Ű�� �Է� ���ۿ� �����ֱ� �����Դϴ�.
	scanf("%s", str);	// not clear input buffer
#else
	int i = 0;
	while(1) {
		str[i]= getchar();	// clear input buffer
		if (str[i] == '\n') break;
		//putchar(str[i]); 
		i++;
	} 
#endif	   
	puts("����� ������ ���ڷ� �����ּ��� : ");
	puts("(����=M, ����=F)");
	scanf("%c", &ch);	

	if (ch == 'm' | ch == 'M')
	{
		printf("����� ������ %s�Դϴ�.\n", str);
	}

	else if (ch == 'f' | ch == 'F')
	{
		printf("����� ������ %s�Դϴ�.\n", str);
	}
	else
	{
		printf("%s��, ������ �߸� �Է��ϼ̽��ϴ�.\n", str);
	}
	return 0;
}