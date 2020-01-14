// InsertionSortLL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 

// Link list node 
struct Node
{
	int data;
	struct Node* next;
};


// Function to insert a given node in a sorted linked list 
void sortedInsert(struct Node**, struct Node*);



// function to sort a singly linked list using insertion sort 
void insertionSort(struct Node **head_ref)
{ 
	struct Node *sorted = NULL;				// Initialize sorted linked list
	struct Node *current = *head_ref;		 // Traverse the given linked list and insert every node to sorted
	
	while (current != NULL)
	{ 
		struct Node *next = current->next;	 // Store next for next iteration
		sortedInsert(&sorted, current);		 // insert current in sorted linked list 
		current = next;						// Update current 
	}

	
	*head_ref = sorted;				// Update head_ref to point to sorted linked list 
}




void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
	struct Node* current;

	if (*head_ref == NULL || (*head_ref)->data >= new_node->data) // Special case for the head end 
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		current = *head_ref;		// Locate the node before the point of insertion 
		while (current->next != NULL &&	current->next->data < new_node->data)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}



/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */

// Function to print linked list
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";		//printf("%d  ", temp->data);
		temp = temp->next;
	}
}



// A utility function to insert a node at the beginning of linked list 
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main()
{
    std::cout << "Hello World!\n"; 

	struct Node *a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	printf("Linked List before sorting \n");
	printList(a);

	insertionSort(&a);

	printf("\nLinked List after sorting \n");
	printList(a);

	return 0;
}

