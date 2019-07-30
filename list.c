

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


static Node* create_node(uint32_t addr)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->addr=addr;
	new_node->next=NULL;
	new_ode->prev=NULL;
	return new_node;
}


static void list_add_head(Blist *list, uint32_t addr)
{
	assert(list!=NULL);
        Node *new_node= create_node(addr);
        new_node->next=list->head;
        list->head=new_node;

        if(list->tail==NULL)
        {
                list->tail=new_node;
        }

        list->length++;

}


Blist* add_new_busy_block(Blist *list, uint32_t addr)
{

        list=list_add_head(list,addr);

	return list;
}


