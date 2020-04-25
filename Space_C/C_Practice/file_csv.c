#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Id, Name, Birth, Address
//1, Tom, 3 - Dec, Glenfiedl
//2, Jone, 12 - Oct, Milford
//3, Wilson, 7 - Jun, Takapuna
typedef struct {
	int id;
	char name[20];
	int b_day;
	char b_mon[10];
	char addr[20];
	char* temp;
}Person;
int putPerson(Person* p, char str[])
{
	char* info;
	info = strtok(str, ",-");
	p->id = atoi(info);
	info = strtok(NULL, ",-");
	strcpy(p->name, info);
	info = strtok(NULL, ",-");
	p->b_day = atoi(info);
	info = strtok(NULL, ",-");
	strcpy(p->b_mon, info);
	info = strtok(NULL, ",-");
	strcpy(p->addr, info);
	printf("[%s] %d, %s, %d-%s, %s", __FUNCTION__,p->id, p->name, p->b_day, p->b_mon, p->addr);
	
	p->temp = (char*)malloc(30);
	sprintf(p->temp, "** %s", p->name);

	/*printf("[%s] %d, %s, %d-%s, %s ..%s", 
		__FUNCTION__, p->id, p->name, p->b_day, p->b_mon, p->addr,p->temp);*/
	return 0;
}


int main()
{
	{
		printf("\n");
		int arr[3][5];
		printf("&arr[0][0]=%p, &arr[0][1]=%p, &arr[1][0]=%p\n",
			&arr[0][0], &arr[0][1], &arr[1][0]);
		printf("&arr[0]=%p, &arr[1]=%p\n", &arr[0], &arr[1]);
		printf("*arr=%p, *(arr+1)=%p, *arr+1=%p\n", *arr, *arr + 1, *(arr + 1));
		printf("arr=%p, arr+1=%p\n", arr, arr + 1);
		printf("&arr=%p, &arr+1=%p\n", &arr, &arr + 1);
		// &(arr + 1) : error
		printf("sizeof(&arr)=%d, sizeof(arr)=%d, sizeof(arr[0])=%d, sizeof(arr[0][0])=%d\n",
			sizeof(&arr), sizeof(arr), sizeof(arr[0]), sizeof(arr[0][0]));
		printf("sizeof(&arr)=%d, sizeof(arr)=%d, sizeof(*arr)=%d, sizeof(**arr)=%d\n",
			sizeof(&arr), sizeof(arr), sizeof(*arr), sizeof(**arr));
		printf("sizeof(arr)/sizeof(arr[0])=%d, sizeof(arr[0])/sizeof(arr[0][0])=%d\n",
			sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]) / sizeof(arr[0][0]));
		printf("sizeof(arr)/sizeof(*arr)=%d, sizeof(*arr)/sizeof(**arr)=%d\n",
			sizeof(arr) / sizeof(*arr), sizeof(*arr) / sizeof(**arr));
		/*
&arr[0][0]=00000081A6B3F458, &arr[0][1]=00000081A6B3F45C, &arr[1][0]=00000081A6B3F46C
&arr[0]=00000081A6B3F458, &arr[1]=00000081A6B3F46C
*arr=00000081A6B3F458, *(arr+1)=00000081A6B3F45C, *arr+1=00000081A6B3F46C
arr=00000081A6B3F458, arr+1=00000081A6B3F46C
&arr=00000081A6B3F458, &arr+1=00000081A6B3F494
sizeof(&arr)=8, sizeof(arr)=60, sizeof(arr[0])=20, sizeof(arr[0][0])=4
sizeof(&arr)=8, sizeof(arr)=60, sizeof(*arr)=20, sizeof(**arr)=4
sizeof(arr)/sizeof(arr[0])=3, sizeof(arr[0])/sizeof(arr[0][0])=5
sizeof(arr)/sizeof(*arr)=3, sizeof(*arr)/sizeof(**arr)=5
		*/
	}


	FILE* pFile = fopen("../txt/mydata.csv","r+");
	
	if (!pFile)
	{
		system("cd");
		printf("\npFile Wrong!\n");
		return 0;
	}
	char str[50] = { NULL, };
	int i = 0;
	Person* person = (Person*)malloc(sizeof(Person)*4);
	//Person person[4];
	while (fgets(str, 50, pFile))
	{
		//fputs(str, stdout);

		putPerson(&person[i], str);
		i++;
	}
	printf("i=%d\n", i);

	for (int j=i-1; j >= 0; j--)
	{
		printf("[%d] %d, %s, %d-%s, %s ..%s",
			j, person[j].id, person[j].name, person[j].b_day, 
			person[j].b_mon, person[j].addr, person[j].temp);

		if(person[j].temp) 
			free(person[j].temp);
	}
	free(person);
	fclose(pFile);
	return 0;
}