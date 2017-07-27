#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node_t_ {
    struct node_t_ * next;
	int32_t          value;
} node_t;


void print(node_t *head)
{
	node_t *p = head;
    while(p) {
	    printf("%d ", p->value);
		p = p->next;
	}
}

node_t *create(int num) 
{
	node_t * head = NULL, *p;
	int32_t i;
    for (i = 0; i < num; ++i){
	    node_t *new = (node_t *)malloc(sizeof(node_t));
		if (new == NULL) {
		    printf("malloc new node failed \n");
		    return;
		}
        new->next = NULL;
		new->value = i;
		if (i == 0) {
			head = p = new;
		}
		else {
	        p->next	= new;
			p = new;
		}
	}		
	return head;
}

void free_list(node_t *head)
{
	node_t *p = head;
    while (p) {
	    node_t *last = p;
		p = p->next;
		free(last);
	}
}

node_t *reverse(node_t *head)
{
    node_t *cur = head, *pre = NULL;
	while (cur) {
	    node_t *next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

int32_t main()
{
	 printf("create list\n");
     node_t *list = create(10);
     
	 printf("list is: \n");
	 print(list);

	 printf("reverse list \n");
	 node_t *list_r = reverse(list);

	 printf("list is: \n");
     print(list_r);

	 free_list(list_r);
}


