#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node_t;

#define TEST_SLL_LOOP 0

/* 
 *this fuction will create initiate the node of type node_t.
 *retrun the node 'start'
 */
node_t *create_node()
{
	printf("entered function: %s\n",__FUNCTION__);
	node_t *start;	// define node 'start'
	start=NULL;	// init node to NULL
	printf("exiting function: %s\n\n",__FUNCTION__);
	return start;	// return node 'start'
}

/* this fuction will create the new node and  copy data into the data field,
 * point the next to NULL and returns the start address
 */

node_t * new_node(int data)
{
	printf("entered function: %s\n",__FUNCTION__);
	node_t * new_node = (node_t*)malloc(sizeof(node_t));
	new_node->data=data;
	new_node->next = NULL;
	printf("exiting function: %s\n",__FUNCTION__);
	return new_node;
}

/* this funcion will add node to head i.e start point of the linked list.
 * returns the start address.
 */

node_t * add_head(node_t *start, int data)
{
	printf("entered function: %s\n",__FUNCTION__);
	node_t * node = new_node(data);
	node->next=start;
	start=node;
	printf("exiting function: %s\n\n",__FUNCTION__);
	return start;
}

/* this function will print list from head to tail */
void print_list(node_t * start)
{
	printf("entered function: %s\n",__FUNCTION__);
	if(start == NULL)
	{
		printf("list is empty. nothing to print!!!\n");
		return;
	}
	node_t * current_node;
	current_node = start;
	/* traverse thru the list until current_node points to NULL */
	while(current_node!=NULL)
	{
		printf("data in node %p is %d\n",current_node,current_node->data);
		current_node = current_node->next;
	}
	printf("exiting function: %s\n\n",__FUNCTION__);
}

/* this function will add node to the list at the tail(i.e, at the end of the lsit). */
node_t * add_tail(node_t * start, int data)
{
	printf("entered function: %s\n",__FUNCTION__);
	node_t *node = new_node(data);
	/* check if recived node is empty, if yes add connect node to recived address directly*/
	if(start == NULL)
	{
		printf("list empty, node directly added to the recieved address\n");
		start = node;
		return start;
	}
	node_t * current_node;
	current_node = start;
	/* using for loop to go till the last node */
	for(current_node=start; current_node->next!=NULL; current_node=current_node->next);
	/* now current_node is pointing to last node, attach new node here */
	current_node->next=node;
	printf("exiting function: %s\n\n",__FUNCTION__);
	return start;
}

/* this function adds node in between the list, i.ex after the specified data(key) */
node_t * add_after_node(node_t * start, int key, int data)
{
	printf("entered function: %s\n",__FUNCTION__);
	node_t *node = new_node(data);
	if(start == NULL)
	{
		printf("list empty, node directly added to the recieved address\n");
		start = node;
		return start;
	}
	node_t * current_node;
	current_node=start;
	for(current_node=start;current_node!=NULL;current_node=current_node->next)
	{
		if(key==current_node->data)
		{
			node_t *temp_node;
			temp_node = current_node->next;
			current_node->next = node;
			node->next = temp_node;
			return start;
		}
	}
	printf("exiting function: %s\n\n",__FUNCTION__);
	return start;
}

/* this function will add node just before the node with key */
node_t * add_before_node(node_t *start,int key, int data)
{
	printf("entered function: %s\n",__FUNCTION__);
	node_t * node = new_node(data);
	if(start == NULL)
	{
		printf("list empty, node directly added to the recieved address\n");
		start = node;
		return start;
	}
	node_t * current_node;
	current_node = start;
	node_t *temp_node;
	if(start->data==key)
	{
		printf("key: %d is present in first node, so add new node at head\n", key);
		start = add_head(start,data);
		return start;
	}
	while(current_node->data!=key)
	{
		if(current_node->next==NULL)
		{
			printf("list completed, key: %d not found\n", key);
			return start;
		}
		temp_node = current_node;
		current_node=current_node->next;
	}
	temp_node->next=node;
	node->next=current_node;
	printf("exiting function: %s\n\n",__FUNCTION__);
	return start;
}

/* this function is used delete head from list */
node_t * delete_head(node_t *start)
{
	printf("entered function: %s\n",__FUNCTION__);
	if(start == NULL)
	{
		printf("list empty, nothing to delete\n");
		return start;
	}
	if(start->next==NULL)
	{
		printf("node start is only node present and will be delted\n");
		//start=NULL;
		free(start);
		return NULL;
	}
	node_t * temp_node;
	temp_node = start;
	start=start->next;
	temp_node = NULL;
	free(temp_node);
	printf("exiting function: %s\n\n",__FUNCTION__);
	return start;
}

/* this function is used delete tail node from list */
node_t * delete_tail(node_t *start)
{
	printf("entered function: %s\n",__FUNCTION__);
	if(start == NULL)
	{
		printf("list empty, nothing to delete\n");
		return start;
	}
	if(start->next==NULL)
	{
		printf("node start is only node present and will be delted\n");
		//start=NULL;
		free(start);
		return NULL;
	}
	node_t * current_node;
	node_t * temp_node;
	current_node = start;
	while(current_node->next!=NULL)
	{
		temp_node=current_node;
		current_node=current_node->next;
	}
	temp_node->next=NULL;
	//current_node=NULL;
	free(current_node);
	printf("exiting function: %s\n\n",__FUNCTION__);
	return start;
}

/* this fuction will delete node having the key */
node_t *delete_key(node_t *start, int key)
{
	printf("entered function: %s\n",__FUNCTION__);
	if(start == NULL)
	{
		printf("list empty, nothing to delete\n");
		return start;
	}
	if (start->next==NULL)
	{
		printf("single node\n");
		if(start->data==key)
		{
			printf("key %d found, it will be deleted\n", key);
			//start=NULL;
			free(start);
			printf("exiting function: %s\n\n",__FUNCTION__);
			return NULL;
		}
		printf("!! but key not found\n");
	}
	if(start->data==key)
	{
		printf("key: %d found in first node, it will be deleted\n",key );
		node_t *temp_node;
		temp_node = start;
		start=start->next;
		//temp_node = NULL;
		free(temp_node);
		printf("exiting function: %s\n\n",__FUNCTION__);
		return start;
	}
	/* now traverse from 2nd node to last node
	* and make temp_node to follow one node behind the current_node */
	node_t * temp_node;
	node_t *current_node;
	current_node = start->next;
	temp_node = start;
	while(current_node!=NULL)
	{
		if(current_node->data==key)
		{
			temp_node->next=current_node->next;
			//current_node=NULL;
			free(current_node);
			printf("exiting function: %s\n\n",__FUNCTION__);
			return start;
		}
		temp_node = current_node;
		current_node = current_node->next;
	}
	printf("exiting function: %s\n\n",__FUNCTION__);
	return start;
}

/* Floyd’s Cycle-Finding Algorithm:
 * This is the fastest method. Traverse linked list using two pointers.
 * Move one pointer by one and other pointer by two. 
 * If these pointers meet at same node then there is a loop. 
 * If pointers do not meet then linked list doesn’t have loop. */

int detectloop(node_t *start) 
{ 
    node_t  *slow_p = start, *fast_p = start; 
   /* checks if none of the pointers reach NULL, if reached, no loops are found */
    while (slow_p && fast_p && fast_p->next )
    { 
        slow_p = slow_p->next;/* move slow_p by one*/
        fast_p  = fast_p->next->next;/* move fast_p by two*/
        if (slow_p == fast_p) 
        { 
           printf("found loop!!!. @ mem location %p\n\n",slow_p); 
           return 1; 
        } 
    } 
    printf("loop not found\n");
    return 0; 
}

int main()
{
	printf("entered function: %s\n",__FUNCTION__);
	node_t * head;
	head = create_node();
	head = add_head(head, 10);
	head = add_head(head, 20);
	print_list(head);
	head = add_tail(head,90);
	head = add_tail(head,80);
	print_list(head);
	head = add_after_node(head,20,30);
	head = add_after_node(head,90,100);
	print_list(head);
	head = add_before_node(head,80,90);
	head = add_before_node(head,50,90);
	head = add_before_node(head,20,25);
	print_list(head);
	head = delete_head(head);
	head = delete_head(head);
	print_list(head);
	head = delete_tail(head);
	head = delete_tail(head);
	print_list(head);
	head = delete_key(head,100);
	head = delete_key(head,90);
	head = delete_tail(head);
	head = delete_key(head,30);
	print_list(head);

	/* this part of code is used to test detection of loop inside linked list
	 * enalble it by updating #define TEST_SLL_LOOP at the begging oh the file
	 */
#if TEST_SLL_LOOP
	head = add_head(head, 10);
	head = add_head(head, 20);
	head = add_tail(head,90);
	head = add_tail(head,80);
	head->next->next->next->next = head; 
	detectloop(head);
#endif

	printf("exiting function: %s\n",__FUNCTION__);
	return 0;
}
