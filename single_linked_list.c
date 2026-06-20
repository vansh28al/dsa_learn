#include<stdlib.h>
#include<stdio.h>
#include "single_linked_list.h"

typedef struct node
{
	struct node* fwd;
	int value;
} node;
typedef struct
{
	node* head;
	int length;
	node* tail;
} oneWayLinkList;

oneWayLinkList* create(void)
{
	oneWayLinkList* r = (oneWayLinkList*)malloc(sizeof(oneWayLinkList));
	if (r)
	{
		r->head = NULL;
		r->tail = NULL;
		r->length = 0;
	}
	return r;
}

void append(oneWayLinkList* self, int v)
{
	node* next = (node*)malloc(sizeof(node));
	if(!next)
	{
		printf("Memory Allocation Failed\n");
		return;
	}

	next->value = v;
	next->fwd = NULL;

	if (self->length > 0)
	{
		self->tail->fwd = next;
		self->tail = next;
	}
	else 
	{
		self->head = next;
		self->tail = next;
	}
	self->length++;
}

void insert(oneWayLinkList* self, int v, int id)
{
	if (id < 0 || id > self->length)
	{
		printf("invalid index\n");
		return;
	}
	if (id == self->length)
	{
		append(self,v);
		return;
	}
	node* new_node = (node*)malloc(sizeof(node));
	if(!new_node)
	{
		printf("Memory Allocation Failed");
		return;
	}
	new_node->value = v;

	if(id==0)
	{
		new_node->fwd = self->head;
		self->head = new_node;
		self->length++;
		return;
	}
	int i;
	node* prev = self->head;
	
	for (i = 0; i < id-1; i++)
	{
		prev = prev->fwd;
	}

	new_node->fwd = prev->fwd;
	prev->fwd = new_node;
	self->length++;
	return;
}

void del(oneWayLinkList* self, int id)
{
	if (id < 0 || id >= self->length)
	{
		printf("invalid index");
		return;
	}
	if (id == 0)
	{
		node* temp = self->head;
		self->head = self->head->fwd;
		free(temp);
		self->length--;
		if (self->length == 0)
		{
			self->tail = NULL;
		}

		return;
	}
	int i;
	if (id == (self->length - 1))
	{
		node* prev = self->head;
		for (i = 0; i < self->length - 2; i++)
		{
			prev = prev->fwd;
		}
		free(prev->fwd);
		prev->fwd = NULL;
		self->tail = prev;
		self->length--;
		return;
	}
	
	node* prev = self->head;
	for(i = 0; i < id - 1; i++)
	{
		prev = prev->fwd;
	}
	node* target = prev->fwd;
	prev->fwd = target->fwd;
	free(target);
	self->length--;
}

void free_list(oneWayLinkList* self)
{
    if (self == NULL)
    {
        return;
    }

    node* curr = self->head;
    node* next_node = NULL;

    while (curr != NULL)
    {
        next_node = curr->fwd; 
        free(curr);            
        curr = next_node;      
    }

    self->head = NULL;
    self->tail = NULL;
    self->length = 0;

    free(self);
}

			


			

