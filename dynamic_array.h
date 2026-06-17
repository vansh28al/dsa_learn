#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

typedef struct
{
	int capacity;
	int length;
	int* array;
} dynamArr;

dynamArr* arrCreate(int cap, int len);
int access_arr(const dynamArr* self, int id);
void append(dynamArr* self, int elem)l
void del(dynamArr* self, int id);
void insert_at(dynamArr* self, int elem, int id)l
void free_array(dynamArr* self);
int find_elem(const dynamArr* self, int elem);

#endif // DYNAMIC_ARRAY_H

