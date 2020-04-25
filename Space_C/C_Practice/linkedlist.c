#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stLinkList {
	int data;
	struct stLinkList* next;
}LinkList;
static int nodeCount;
LinkList* CreateList()
{
	LinkList* plist = malloc(sizeof(LinkList));
	plist->data = 0;
	plist->next = NULL;

	return plist;
}

LinkList* InsertList(LinkList* plist, int data)
{
	if (!plist) return NULL;

	LinkList* newlist= malloc(sizeof(LinkList));
	newlist->data = data;
	newlist->next = plist->next;
	plist->next = newlist;
	++nodeCount;
	return newlist;
}

// deleting the next node... free is a main function...
void DeleteList(LinkList* plist)
{
	LinkList* tmp = plist->next;
	plist->next = tmp->next;
	--nodeCount;
	free(tmp);
	tmp = NULL;
}
void PrintList(LinkList* head)
{
	if (!head) return;
	LinkList* curlist = head->next;
	int i = 0;
	while (curlist)
	{
		printf("[%d] %d\n", i++, curlist->data);
		curlist = curlist->next;
	}

}

#define TMP	1
void PrintReverseList(LinkList* head)
{
#if TMP
	int* rData = (int*)malloc(sizeof(int) * nodeCount);
	memset(rData, NULL, sizeof(int) * nodeCount);
#endif
	LinkList* curlist = head->next;
	int i = nodeCount;

	while (curlist)
	{
#if TMP
		rData[--i] = curlist->data;
#endif
		curlist = curlist->next;
	}
	//printf("i=%d\n", i);
#if TMP
	for (i=0; i< nodeCount; i++)
		printf("%d ", rData[i]);

	free(rData);
#endif
}
void DeleteAllList(LinkList* head)
{
	LinkList* node = head;
	while (node)
	{
		LinkList* nextNode = node->next;
		free(node);
		node = nextNode;
	}
}
int main()
{
	LinkList* head = CreateList();
	LinkList* list[100];
	int i = 0;
	list[0]= InsertList(head, 11);
	list[1] =InsertList(list[0], 12);
	list[2] = InsertList(list[1], 13);
	list[3] = InsertList(list[2], 14);
	list[4] = InsertList(list[3], 15);
	list[5] = InsertList(list[4], 16);
	list[6] = InsertList(list[5], 17);

	//PrintList(head);
	//DeleteList(list[3]);
	printf("----\n");
	PrintList(head);
#if 0
	DeleteAllList(head);
	printf("----\n");
	PrintList(head);
#endif
	printf("----\n");
	PrintReverseList(head);
	return 0;

}