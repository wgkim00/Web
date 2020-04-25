#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


#ifdef _TIME_MEASURE_
#include <time.h>

clock_t start_t, end_t;
start_t = clock();
end_t = clock();
printf("\n %elip_time=%.1lf\n",(double)(end_t - start_t) / CLOCKS_PER_SEC);
#endif

pLINK_ONE_WAY CreateListHead(int data)
{
	pLINK_ONE_WAY head = (pLINK_ONE_WAY)malloc(sizeof(LINK_ONE_WAY));
	if (head != NULL)
	{
		head->data = data;
		head->next = NULL;
	}

	return head;
}
pLINK_ONE_WAY InsertNode(pLINK_ONE_WAY prevNode, int data)
{
	pLINK_ONE_WAY node = (pLINK_ONE_WAY)malloc(sizeof(LINK_ONE_WAY));
	if (node == NULL || prevNode == NULL) return NULL;
	
	node->data = data;
	node->next = prevNode->next;

	prevNode->next = node;

	return node;
}

// https://modoocode.com/100
void DeleteNode(pLINK_ONE_WAY target, pLINK_ONE_WAY head)
{
	if (target == NULL || head == NULL) return ;
	if (target == head)
	{
		free(target);
		return;
	}

	pLINK_ONE_WAY next = head;
	while (next)
	{
		if (next->next == target)
		{
			next->next = target->next;
			free(target);
			break;
		}
		next = next->next;
	}
}

int FindNode(pLINK_ONE_WAY target, pLINK_ONE_WAY head)
{
	pLINK_ONE_WAY node = head;
	while (node)
	{
		if (node == target) return 1;
		node = node->next;
	}
	return 0;
}

pLINK_ONE_WAY FindIndex(int n, pLINK_ONE_WAY head)
{
	int index = 0;
	pLINK_ONE_WAY node = head;

	while (node)
	{
		if (index == n) return node;
		node = node->next;
		index++;
	}

	return 0;
}

int GetNodeIndex(pLINK_ONE_WAY target, pLINK_ONE_WAY head)
{
	if (target == NULL) return 0;
	pLINK_ONE_WAY node = head;
	int index = 0;

	while (node)
	{
		if (node == target) return index;
		index++;
		node = node->next;
	}
}

void PrintNodes(pLINK_ONE_WAY node)
{
	while (node)
	{
		printf("%d ", node->data);
		node=node->next;
	}
}

#define PrintVariableName(var) printf(#var "\n")

int main()
{
	pLINK_ONE_WAY head = CreateListHead(0);
	pLINK_ONE_WAY node1 = InsertNode(head, 1);
	pLINK_ONE_WAY node2 = InsertNode(node1, 2);
	pLINK_ONE_WAY node3 = InsertNode(node2, 3);
	pLINK_ONE_WAY node4 = InsertNode(node3, 4);
	PrintNodes(head);
	printf("\n");
	printf("find node1: %s\n", FindNode(node1, head) ? "Found":"Not found");
	int num = GetNodeIndex(node1, head);
	printf("find the order of node1= %d\n", num);
	num = GetNodeIndex(node2, head);
	printf("find the order of node2= %d\n", num);
	num = GetNodeIndex(node3, head);
	printf("find the order of node3= %d\n", num);

	DeleteNode(node1, head);
	PrintNodes(head);
	printf("\n\n");
	printf("find node1: %s\n", FindNode(node1, head) ? "Found" : "Not found");
	pLINK_ONE_WAY tmp = FindIndex(0, head);
	printf("find 1st data= %d\n", tmp->data);
	 tmp = FindIndex(1, head);
	printf("find 2nd data= %d\n", tmp->data);
	 tmp = FindIndex(2, head);
	printf("find 3rd data= %d\n", tmp->data);
	 tmp = FindIndex(3, head);
	printf("find 4th data= %d\n", tmp->data);
	PrintVariableName(333);
	//printf(#bb "\n");


}