#include <stdio.h>

#define XN(x,n) x ## n

#ifndef __STDC__
#define __STDC__	1
#else
#error "Not standard C"
#endif

int CheckPowerOftwo(unsigned int x)
{
	return ((x != 0) && (!(x & (x - 1))));         // = return (x  && (!(x & (x - 1))));
}
int CheckPowerOftwo1(unsigned int x)
{
	return (x && (!(x & (x - 1))));
}

int main()
{
	{
		int XN(x, 1) = 10;
		int XN(y, 1) = 20;
		printf("%d %d %d(%x) %d(%x)\n", x1, y1, ~0, ~0, ~1, ~1);
		printf("%d\n", __STDC__);
		printf("%d %d %d %d\n",
			CheckPowerOftwo(8), CheckPowerOftwo(0),
			CheckPowerOftwo(16), CheckPowerOftwo(46));
		printf("%d %d %d %d\n",
			CheckPowerOftwo1(8), CheckPowerOftwo1(1),
			CheckPowerOftwo1(16), CheckPowerOftwo1(46));
		printf("%d %d %d %d\n",
			CheckPowerOftwo1(-8), CheckPowerOftwo1(-3),
			CheckPowerOftwo1(-16), CheckPowerOftwo1(-46));
		printf("%d %d %d %d\n",
			CheckPowerOftwo1(-8), CheckPowerOftwo1(-3),
			CheckPowerOftwo1(-16), CheckPowerOftwo1(-46));
		printf("%d %d %d %d \n", -1 << 4, -1 >> 4, -30 << 1, -30 >> 1);
		printf("%d %d %d %d \n", 1 << 1, 1 >> 1, -1 << 1, -1 >> 1);
		printf("%d %d %d %d \n", 30 << 1, 30 >> 1, -30 << 1, -30 >> 1);
		printf("%d %d %d %d \n", 7 << 1, 7 >> 1, -7 << 1, -7 >> 1);
		printf("Computer", "Programming");       // Computer
		printf("Computer" "Programming");       // ComputerProgramming
/*
10 20 -1(ffffffff) -2(fffffffe)
1
1 0 1 0
1 1 1 0
0 0 0 0
0 0 0 0
-16 -1 -60 -15
2 0 -2 -1
60 15 -60 -15
14 3 -14 -4
ComputerComputerProgramming
*/
	}
}