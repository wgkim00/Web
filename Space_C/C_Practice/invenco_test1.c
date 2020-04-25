// Invenco 
// Embedded Engineer 2019

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void AddNMEATTail(unsigned char* msg)
{
	unsigned char Checksum;
	unsigned int Pos;
	unsigned char TempStr[6];

	Checksum = 0;
	for (Pos = 1; msg[Pos]; Checksum ^= msg[Pos++])
	{
		;
	}

	sprintf(TempStr, "*%02X\r\n", Checksum);// -->  *65
	strcat(msg, TempStr);

}

int main()
{
	unsigned char string[] = "abcd\0efg\0\0\0\0\0\0";
	AddNMEATTail(string);

	printf(string);// --> abcd*65
	return 0;
}