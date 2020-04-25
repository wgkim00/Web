#include <stdio.h>

main()
{
	

	//create an array of structure;
	int aiData[] = { 1,2,3,4,5 };


	//Create two pointer to the integer
	int* piData1 = NULL;
	int* piData2 = NULL;

	int iOffset = 0;

	//Assign the address of array first element to the pointer
	piData1 = &aiData[0];

	//Assign the address of array third element to the pointer
	piData2 = &aiData[5];

	// Subtract the pointer
	iOffset = piData2 - piData1;

	printf("pointer offset  =  %d\n\n", iOffset);	// 5

	int arr[5] = { 11,21,31,41,51 };
	printf("arr= %u\n", arr);
	printf("&arr= %u\n", &arr);
	printf("arr+1 = %u\n", arr + 1);
	printf("&arr+1 = %u\n", &arr + 1);
	printf("*(&arr+1)-arr = %u\n\n", *(&arr + 1) - arr);	// how many elements in array


}