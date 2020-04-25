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

	Node* curr = (Node*)malloc(sizeof(Node));
	curr->data = data;
	curr->next = NULL;

	if (*head == NULL)
	{
		*head = curr;
		return;
	}
	Node* tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = curr;
}

void insertPos(Node* curr, int data)
{
	if (curr == NULL) return;

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = curr->next;
	curr->next = tmp;
}
int reverse(Node** head)
{
	Node* curr = *head;
	Node* prev = NULL;
	Node* next = NULL;

	if (curr == NULL) return;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	*head = prev;
}

void deleteData(Node** head, int data)
{
	Node* curr = *head;
	Node* prev = NULL;
	int pos = 0;
	if (curr->data == data)
	{
		*head = curr->next;
		free(curr);
		return;
	}
	while (curr)
	{
		if (curr->data == data)
		{
			if(pos==0) 
			{
				*head = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
			free(curr);
			break;
		}
		prev = curr;
		curr = curr->next;
		++pos;
	}
}
void deletePos(Node** head, int pos)
{
	if (*head == NULL) return;
	Node* curr = *head;
	Node* prev = NULL;

	if (pos <= 0)
	{
		*head = curr->next;
		free(curr);
		return;
	}
	for (int i = 1; curr!=NULL && i <= pos; ++i)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
}
void deleteAll(Node** head)
{
	Node* curr = *head;
	Node* next = NULL;
	while (curr)
	{
		next = curr->next;
		free(curr); 
		curr = next->next;
	}
	*head = NULL;
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

	insertEnd(&head, 51);
	insertEnd(&head, 52);
	insertEnd(&head, 53);
	insertPos(head->next->next, 99);
	insertPos(head->next, 98);

	printNode(head);
	reverse(&head);
	printNode(head);

	deleteData(&head,53);
	deleteData(&head,99);
	printNode(head);

	deletePos(&head, 3);
	printNode(head);
}