#include <stdio.h>
#include <stdlib.h>

typedef struct stNode
{
	int data;
	struct stNode* next;
}Node;

void insertFront(Node** head, int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = *head;
	*head = node;
}
void insertEnd(Node** head, int data)
{
	Node* curr = malloc(sizeof(Node));
	curr->data = data;
	curr->next = NULL;
	
	Node* tmp = *head;
	if (tmp == NULL)
	{
		tmp = curr; 
		*head = curr;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = curr;
}
void insertNode(Node* curr, int data)
{
	if (curr == NULL) return;

	Node* next = malloc(sizeof (Node));
	next->data = data;
	next->next = curr->next;
	curr->next = next;
}

void reverse(Node** head)
{
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
void exchange(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void deleteByIndex(Node** head, int index)
{
	Node* curr = *head;
	Node* prev = NULL;
	int pos = 0;

	if (*head == NULL) return;
	if (index == 0)
	{
		*head = curr->next;
		free(curr); curr = NULL;
		return;
	}
	for (pos = 1; curr!=NULL && pos <= index; ++pos)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr); curr = NULL;
}
void deleteByData(Node** head, int data)
{
	if (*head == NULL) return;

	Node* curr = *head;
	Node* prev = NULL;
	while (curr)
	{
		if (curr->data == data)
		{
			if (curr == *head)
				*head = curr->next;
			else
				prev->next = curr->next;
			free(curr); curr = NULL;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

void deleteAll(Node** head)
{
	Node* curr = *head;
	Node* next = NULL;
	if (*head == NULL) return;
	while (curr)
	{
		next = curr->next;
		free(curr); curr = NULL;
		curr = next;
	}
	*head = NULL;
}
int main()
{
	Node* head = NULL;
	insertEnd(&head, 100);
	insertFront(&head, 10);
	insertFront(&head, 11);
	insertFront(&head, 12);
	insertFront(&head, 13);
	insertEnd(&head, 101);
	insertEnd(&head, 102);
	insertEnd(&head, 103);
	insertNode(head, 300);
	insertNode(head, 301);

	printNode(head);

	reverse(&head);
	printNode(head);

	deleteByData(&head,101);
	deleteByData(&head, 13);
	deleteByData(&head,103);
	printNode(head);
	deleteByIndex(&head,3);
	deleteByIndex(&head, 0);
	printNode(head);

	deleteAll(&head);
	printNode(head);

	int a = 30;
	int b = 50;
	exchange(&a, &b);
	printf("a=%d, b=%d\n",  a, b);
}