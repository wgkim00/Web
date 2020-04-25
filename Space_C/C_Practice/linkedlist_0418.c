#include <stdio.h>
#include <stdlib.h>

typedef struct stNode
{
	int data;
	struct stNode* next;
}Node;

void insertFront(Node** head, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void insertEnd(Node** head, int data)
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	Node* last = *head;
	if (last == NULL)
	{
		last = node;
		return;
	}
	while (last->next)
	{
		last = last->next;
	}

	last->next = node;
}
void insertNode(Node* curr, int data)
{
	if (curr == NULL) return;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = curr->next;
	curr->next = newNode;
}

void deleteByData(Node**head,int data)
{
	Node* curr = *head;
	Node* prev = NULL;
	if (curr == NULL) return;
	while (curr)
	{
		if (curr->data == data)
		{
			if (curr == *head)
			{
				*head = curr->next;
				free(curr);
				break;
			}
			prev->next = curr->next;
			free(curr);
			curr = prev->next;/*있어야 할까 없어도 될까*/
			break;
		}
		prev = curr;
		curr = curr->next;
	}
}

void deleteByPos(Node** head, int pos)
{
	Node* curr = *head;
	Node* prev = NULL;
	int i = 0;
	if (pos == 0)
	{
		*head = curr->next;
		free(curr);
		return;
	}
	for (i = 1; curr!=NULL && i <= pos; ++i)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
}
void reverse(Node** head)
{
	if (head == NULL) return;
	Node* curr = *head;
	Node* prev = NULL;
	Node* next = NULL;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	*head = prev;
}
void deleteAll(Node* head)
{
	Node* curr = head;
	Node* next = NULL;
	if (head == NULL) return;
	int i = 0;
	while (curr)
	{
		next = curr->next;
		free(curr); curr = NULL;
		curr = next;
		++i;
	}
	head = NULL;
	printf("--> free count= %d", i);
}
void printNode(Node* head)
{
	Node* curr = head;
	int count = 0;
	while (curr)
	{
		printf("%d ", curr->data);
		curr = curr->next;
		++count;
	}
	printf("[%d]\n", count);
}
int main()
{
	Node* head = NULL;
	insertFront(&head, 10);
	insertFront(&head, 11);
	insertFront(&head, 12);
	insertFront(&head, 13);

	insertEnd(&head, 200);
	insertEnd(&head, 201);
	insertEnd(&head, 202);

	insertNode(head, 100);
	insertNode(head->next, 101);

	printNode(head);
	reverse(&head);
	printNode(head);

	deleteByData(&head, 13);
	deleteByData(&head, 200);
	printNode(head);
	deleteByPos(&head, 0);
	deleteByPos(&head, 4);
	printNode(head);

	deleteAll(head);
}