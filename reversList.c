#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
};
void printList(struct list * temp)
{
	while(temp!= NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}printf("NULL\n");
}
static void reverse(struct list** head)
{
    struct list* prev   = NULL;
    struct list* current = *head;
    struct list* current1 = *head;
    struct list* next;
    while(current != NULL)
    {
        int k=2;
    while(current != NULL && k)
    {
        	next  = current->next;  
        	current->next = prev;   
        	prev = current;
        	current = next;
        	(*head)->next=next;
        	k--;
    }
        //if(current==NULL) break;
    }
    	*head = current1->next;
}
void push(struct list** head_ref, int new_data)
{
    /* allocate node */
    struct list* new_node =
        (struct list*) malloc(sizeof(struct list));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
int main()
{
	struct list *head = NULL;
	push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 34);
    push(&head, 23);
    push(&head, 11);
 printList(head);
 reverse(&head);
	printList(head);
	return 0;
}