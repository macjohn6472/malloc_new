#ifndef _LIST_H_
#define _LIST_H_

#include <stdint.h>

typedef struct _node_ Node;
typedef struct _free_list_  Flist;
typedef struct _busy_list_ Blist;


struct _node_ {

	uint32_t  addr;
	uint32_t size;
	Node *next;
	Node *prev;
	
};


struct _free_list_ {
	
	uint32_t length;
	Node *head;
	Node *tail;
};

struct _busy_list_ {

	uint32_t length;
	Node *head;
	Node *tail;

};


Flist new_free_list();
Blist new_busy_list();

uint32_t busy_list_length(Blist *list);
uint32_t free_list_length(Flist *list);


static Node* create_node( uint32_t size);


static void list_add_tail(Blist *list, uint32_t size);
void *my_malloc(uint32_t nbytes);


Blist* add_new_busy_block(Blist *list, uint32_t size);
Flist* add_new_free_block(Flist *list, uint32_t size);































#endif
