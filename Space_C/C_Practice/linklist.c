#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

// https://modoocode.com/100
// https://dojang.io/mod/page/view.php?id=646
// should practice stack, queue, tree...

pLINK_ONE_WAY CreateNode(int data)
{
	pLINK_ONE_WAY head = (pLINK_ONE_WAY)malloc(sizeof(LINK_ONE_WAY));
	head->data = data;
	head->next = NULL;
	return head;
}

pLINK_ONE_WAY InsertNode(pLINK_ONE_WAY prevNode, int data)
{
	//pLINK_ONE_WAY prev = prevNode->next;
	pLINK_ONE_WAY newNode = (pLINK_ONE_WAY)malloc(sizeof(LINK_ONE_WAY));

	newNode->data = data;
	newNode->next = prevNode->next;

	prevNode->next = newNode;

	return newNode;
}


void DeleteNode(pLINK_ONE_WAY curNode)
{
	if (curNode == NULL) return;

	if (curNode->next != NULL)
	{
		pLINK_ONE_WAY tempNode= curNode->next;
		curNode->next = tempNode->next;

		free(tempNode);
	}
}

// https://modoocode.com/100
int CountNodes(pLINK_ONE_WAY head)
{
	int count = 1;
	while (head->next != NULL)
	{
		head = head->next;
		count++;
	}
	printf("cont=%d\n",count);
	return count;
}
void printNodes(pLINK_ONE_WAY prtNode)
{
	while (prtNode != NULL)
	{
		printf("data=%d\n", prtNode->data);
		prtNode = prtNode->next;
	}
}

//https://modoocode.com/100
int SearchNode(pLINK_ONE_WAY head, pLINK_ONE_WAY target)
{
	while (head != NULL)
	{
		if (head->next == target) return 1;
		else head = head->next;
	}
	return 0;
}
int main()
{
	pLINK_ONE_WAY head = CreateNode(100);

	pLINK_ONE_WAY node1 = InsertNode(head, 101);
	pLINK_ONE_WAY node2 = InsertNode(node1, 102);
	pLINK_ONE_WAY node3 = InsertNode(node2, 103);
	pLINK_ONE_WAY node4 = InsertNode(node3, 104);

	printNodes(head);
	CountNodes(head);
	if (node1 != NULL)
	{
		printf("node1=%p\n", node1);
		printf("%s\n", SearchNode(head, node1)==1 ? "FOUND" : "NOT FOUND");
	}

	printf("\n\n");

	pLINK_ONE_WAY node10 = InsertNode(node1, 110);
	pLINK_ONE_WAY node20 = InsertNode(node2, 120);
	printNodes(head);
	CountNodes(head);
	printf("%s\n", SearchNode(head, node10) ? "FOUND" : "NOT FOUND");

	printf("\n\n");

	DeleteNode(node1);
	DeleteNode(node2);
	printNodes(head);	
	CountNodes(head);
	printf("%s\n", SearchNode(head, node10) ? "FOUND" : "NOT FOUND");

}