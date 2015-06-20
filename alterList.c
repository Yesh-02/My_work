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
void segregateEvenOdd(struct list * head)
{
	struct list * slow = head;
	struct list * fast = head->next;
	while(fast!=NULL)
	{
		if ( slow->data %2 == 0)
		{
			slow=slow->next;
			fast=fast->next;
		}
		else if ( slow->data % 2 !=0 && fast->data %2 == 0)
		{
			slow->data=slow->data+fast->data;
			fast->data=slow->data-fast->data;
			slow->data=slow->data-fast->data;
			slow=slow->next;
			fast=fast->next;
		}
		else if (slow->data % 2 !=0 && fast->data %2 != 0)
		{
			fast=fast->next;
		}
	}
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
	push(&head, 7);
    push(&head, 61);
    push(&head, 50);
    push(&head, 46);
    push(&head, 34);
    push(&head, 23);
    push(&head, 11);
 printList(head);
	segregateEvenOdd(head); 
	printList(head);
	return 0;
}