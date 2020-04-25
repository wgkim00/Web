#include <stdio.h>


main()
{
	unsigned int i = 0x1234;
	i *= 0x10;
	printf("%p", i);
}
