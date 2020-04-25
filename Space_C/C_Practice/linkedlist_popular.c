// https://www.geeksforgeeks.org/data-structures/linked-list/
// https://www.geeksforgeeks.org/practice-questions-for-linked-list-and-recursion/
// https://www.geeksforgeeks.org/programmers-approach-looking-array-vs-linked-list/?ref=lbp

// the simplistic approach of creating linked list using an array
// a linked list of empty nodes as well in the same array. 
// management of this memory pool (which is basically an array)

#include<stdio.h> 
#include<stdlib.h> 

#define _ORG 0


#if 0
In this post, methods to insert a new node in linked list are discussed.A node can be added in three ways
1) At the front of the linked list	--> push
2) After a given node.				--> insertAfter
3) At the end of the linked list.	--> append
#endif
/* A linked list node */
struct Node
{
	int data;
	struct Node* next;
};

/* UTILITY FUNCTIONS TO TEST fun1() and fun2() */

/* Prints a linked list in reverse manner */
void fun1(struct Node* head)
{
	if (head == NULL)
		return;

	fun1(head->next);
	printf("%d ", head->data);
}

/* prints alternate nodes of a Linked List, first
from head to end, and then from end to head. */
void fun2(struct Node* start)
{
	if (start == NULL)
		return;
	printf("*%d ", start->data);

	if (start->next != NULL)
		fun2(start->next->next);
	printf("**%d ", start->data);
}


/* Function to delete the entire linked list */
// https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
void deleteList(struct Node** head_ref)
{
	/* deref head_ref to get the real head */
	struct Node* current = *head_ref;
	struct Node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	/* deref head_ref to affect the real head back in the caller. */
	*head_ref = NULL;
}

/* Given a reference (pointer to pointer) to the head of a list and an int, 
push a new node on the front of the list. */

// Add a node at the front: (A 4 steps process)
void push(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}
/* Given a node prev_node, insert a new node after the given prev_node */
void insertAfter(struct Node* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* 3. put in the data  */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}
/* Given a reference (pointer to pointer) to the head of a list and an int, 
appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node* last = *head_ref;  /* used in step 5*/

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so make next of
		  it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}
// This function prints contents of linked list starting from head 
void printList(struct Node* node)
{
	while (node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

// https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
/* Counts the no. of occurrences of a node (search_for) in a linked list (head)*/
int getCount(struct Node* head)
{
#if 0		// Recursive Solution
	// Base case 
	if (head == NULL)
		return 0;
	// count is 1 + count of remaining list 
	return 1 + getCount(head->next);
#else		//Iterative Solution
	int count = 0; // Initialize count  
	struct Node* current = head; // Initialize current  
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
#endif

}
/* Given a reference (pointer to pointer) to the head of a list and a key, 
deletes the first occurrence of key in linked list */
#if _ORG
void deleteNodebyKey(struct Node** head_ref, int key)
{
	// Store head node 
	struct Node* temp = *head_ref, * prev = NULL;

	// If head node itself holds the key to be deleted 
	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;   // Changed head 
		free(temp);               // free old head 
		return;
	}

	// Search for the key to be deleted, keep track of the 
	// previous node as we need to change 'prev->next' 
	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list 
	if (temp == NULL) return;

	// Unlink the node from linked list 
	prev->next = temp->next;

	free(temp);  // Free memory 
} 
#else
void deleteNodebyKey(struct Node** head_ref, int key)
{
	// If linked list is empty 
	if (*head_ref == NULL)
		return;

	struct Node* tmp = *head_ref;
	struct Node* prev = NULL;
	int count = 0;

	while (tmp)
	{
		if (tmp->data == key)
		{
			// If head node(count=0) itself holds the key to be deleted 
			if (count == 0)		
			{
				*head_ref = tmp->next;
				free(tmp);
				break;
			}
			else
			{
				prev->next = tmp->next;
				free(tmp);
				break;
			}
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
		count++;
	}
}
#endif
/* Given a reference (pointer to pointer) to the head of a list and a position, 
deletes the node at the given position */
#if _ORG
void deleteNodebyPos(struct Node** head_ref, int position)
{
	// If linked list is empty 
	if (*head_ref == NULL)
		return;

	// Store head node 
	struct Node* temp = *head_ref;
	struct Node* prev =NULL;

	// If head needs to be removed 
	if (position <= 0)
	{
		*head_ref = temp->next;   // Change head 
		free(temp);               // free old head 
		return;
	}

	// Find previous node of the node to be deleted 
	//for (int i = 0; temp != NULL && i < position - 1; i++)
	for (int i = 1; temp != NULL && i <= position ; i++)
	{
		prev = temp;
		temp = temp->next;
	}

	// If position is more than number of ndoes 
	if (temp == NULL || temp->next == NULL)
		return;

	// Node temp is the node to be deleted
	// Unlink the node from linked list 
	prev->next = temp->next;
	free(temp);
}
#else
void deleteNodebyPos(struct Node** head_ref, int pos)
{
	// If linked list is empty 
	if (*head_ref == NULL) return;

	struct Node* tmp = *head_ref;
	struct Node* prev = NULL;

	if (pos <= 0)
	{
		*head_ref = tmp->next;
		free(tmp);
	}
	else
	{
		for (int i = 1; tmp != NULL && i <= pos; i++)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = tmp->next;
		free(tmp);
	}
}
#endif


int searchByKey(struct Node* head, int data)
{
	if (head == NULL) return -1;
	struct Node* tmp = head;

	// if the key not fpund, pos should be -1
	int pos = 0;
	while (tmp)
	{
		if (tmp->data == data) return pos;

		tmp = tmp->next;
		pos++;
	}
	return -1;
}


// Takes head pointer of the linked list and index as arguments and   
// return data at index 
int getKeybyNode(struct Node* head, int node)
{
	if (head == NULL) return -1;

	struct Node* tmp = head;
	for (int i = 0; tmp != NULL && i != node; i++)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL) return -1;

	return tmp->data;
}


// https://www.geeksforgeeks.org/reverse-a-linked-list/
/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next = NULL;
	while (current != NULL) {
		// Store next 
		next = current->next;

		// Reverse current node's pointer 
		current->next = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	}
	*head_ref = prev;
}


/* Driver program to test above functions */
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	int count;			// total node number
	int key = -1;		// node data;
	int pos = -1;		// node position

	/* Using push() to construct below list
		1->2->3->4->5 */
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	count = getCount(head);
	printf("[%d]\n", count);
#if 0
	printf("Output of fun1() for list 1->2->3->4->5 \n");
	fun1(head);

	printf("\nOutput of fun2() for list 1->2->3->4->5 \n");
	fun2(head);

	printf("\n-----------\n");
#endif
	append(&head, 10);
	append(&head, 11);
	append(&head, 12);
	append(&head, 13);
	printList(head);
	count = getCount(head);
	printf("[%d]\n", count);

	insertAfter(head->next, 100);
	printList(head);
	count = getCount(head);
	printf("[%d]\n", count);


	reverse(&head);
	printList(head);
	count = getCount(head);
	printf("[%d]\n", count);

	deleteNodebyKey(&head, 100);
	printList(head);
	count = getCount(head);
	printf("[%d]\n", count);
	
	deleteNodebyPos(&head, 4);
	printList(head);
	count = getCount(head);
	printf("[%d]\n", count);

	key = 3;
	pos = searchByKey(head, key);
	printf("pos=%d for %d\n", pos, key);
	key = 31;
	pos = searchByKey(head, key);
	printf("pos=%d for %d\n", pos, key);

	deleteNodebyPos(&head, pos);
	printList(head);
	count = getCount(head);
	printf("[%d]\n", count);

#if 1
	pos = 3;
	key=getKeybyNode(head, pos);
	printf("pos=%d for %d\n", pos, key);
	pos = 5;
	key = getKeybyNode(head, pos);
	printf("pos=%d for %d\n", pos, key);
#endif
	getchar();
	return 0;
}
