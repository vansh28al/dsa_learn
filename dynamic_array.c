#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

typedef struct 
{
	int capacity;
	int length;
	int* array;
}  dynamArr;

dynamArr* arrCreate(int cap, int len)
{
	dynamArr* r = (dynamArr*)malloc(sizeof(dynamArr);
			if (r != NULL)
			{
			r->capacity = cap;
			r->length = len;
			r->array = malloc(sizeof(int) * cap);
			}

			return r;
			}

			int access_arr(const dynamArr* self, int id)
			{
			if (id >= self->length || id < 0)
			{
			return ERANGE;
			}

			return self->array[id];
			}

void append(dynamArr* self, int elem)
{
	int* new_loc;
	if (self->length >= self->capacity)
	{
		self->capacity *= 2; 
		new_loc = realloc(self->array, sizeof(int) * self->capacity);
		if (!new_loc)
		{
			printf("Memory Allocation Failed");
			self->capacity /= 2;
			return;
		}
		self->array = new_loc;
	}
	self->array[self->length] = elem;
	self->length++;

}

