//http://tcpschool.com/c/c_io_console

#include <stdio.h>

int main(void)
{
	char str[20] = { NULL, };
	char ch;

	puts("당신의 이름을 적어주세요 : ");
#if 0
	// 사용자가 이름을 입력할 수 있지만, 성별은 입력하지 못하고 프로그램이 종료됩니다.
	// 그 이유는 이름을 입력받을 때 마지막으로 입력한 엔터(Enter) 키가 입력 버퍼에 남아있기 때문입니다.
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
	puts("당신의 성별을 약자로 적어주세요 : ");
	puts("(남성=M, 여성=F)");
	scanf("%c", &ch);	

	if (ch == 'm' | ch == 'M')
	{
		printf("당신은 남성인 %s입니다.\n", str);
	}

	else if (ch == 'f' | ch == 'F')
	{
		printf("당신은 여성인 %s입니다.\n", str);
	}
	else
	{
		printf("%s님, 성별을 잘못 입력하셨습니다.\n", str);
	}
	return 0;
}