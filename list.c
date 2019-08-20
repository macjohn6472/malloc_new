

#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include "list.h"


Flist new_free_list() 
{
	Flist list={0,NULL,NULL};
	return list;
}

Blist new_busy_list()
{
        Blist list={0,NULL,NULL};
        return list;
}



uint32_t busy_list_length(Blist *list);
{
	assert(list!=NULL);
	return list->length;
}

uint32_t free_list_length(Flist *list);
{
        assert(list!=NULL);
        return list->length;
}


static Node* create_node( uint32_t size)
{
	Node *new_node = (Node*)my_malloc(sizeof(Node) + size);
	new_node->addr=NULL;
	new_node->next=NULL;
	new_ode->prev=NULL;
	return new_node;
}

void *my_malloc(uint32_t nbytes)
{
	void *b;
	int *p, *end;
	int count =0;

	b = sbrk(0);
        p = (int *)b;
        printf("address =%p \r\n", p);

	end = p + nbytes;
	brk(end);
	while (p < end) 
	{
        	*p = count++;
        	printf("address[%p] =%d \r\n", p, *p);
        	p=p+1;
	}
   	//brk(b);
    	return end;
}
	


static void list_add_tail(Blist *list, uint32_t size)
{
	assert(list!=NULL);
        Node *new_node= create_node(size);
	new_node->prev=list->tail;
	
	list->tail->addr=new_node;
        list->tail=new_node;


	 if(list->head==NULL)
        {
                list->head=new_node;
        }

        list->length++;

}


Blist* add_new_busy_block(Blist *list, uint32_t size)
{

        list=list_add_tail(list,size);

	return list;
}


Flist* add_new_free_block(Flist *list, uint32_t size)
{

        list=list_add_tail(list,size);

	return list;
}

