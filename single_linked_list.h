#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
 
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

  
oneWayLinkList* create(void);  
void append(oneWayLinkList* self, int v);  
void insert(oneWayLinkList* self, int v, int id);  
void del(oneWayLinkList* self, int id);  
void free_list(oneWayLinkList* self); 
void reverse(oneWayLinkList* self);

eendif 
