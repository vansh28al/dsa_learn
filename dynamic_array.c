#include "dynamic_array.h"

typedef struct 
{
	int capacity;
	int length;
	int* array;
}  dynamArr;

dynamArr* arrCreate(int cap, int len)
{
	dynamArr* r = (dynamArr*)malloc(sizeof(dynamArr));
	if (r != NULL)
	{
		r->capacity = cap;
		r->length = len;
		r->array = malloc(sizeof(int) * cap);
		if (!r->array)
		{
			printf("Memory allocation failed\n");
			free(r);
			return NULL;
	}

	return r;
}

int access_arr(const dynamArr* self, int id)
{
	if (id >= self->length || id < 0)
	{
		printf("Invalid index | Assigned Error Code 34");
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
			printf("Memory Allocation Failed\n");
			self->capacity /= 2;
			return;
		}
		self->array = new_loc;
	}
	self->array[self->length] = elem;
	self->length++;

}

void del(dynamArr* self, int id)
{
	if (id < 0 || id >= self->length)
        {
                printf("Invalid Index\n");
                return;
        }

	if (self->length == 1)
	{
		free(self->array);
		self->array = NULL;
		self->length = 0;
		self->capacity = 0;
		printf("Array deleted\n");
		return;
	}

	int* new_loc;
	int i;
	for (i = id; i < (self->length - 1); i++)
	{
		self->array[i] = self->array[i+1];
	}
	self->length--;
	if (self->length <= 0.25 * self->capacity)
	{
		new_loc = realloc(self->array, sizeof(int) * (self->length*2));

		if (!new_loc)
		{
			printf("Memory Reallocation failed\n");
			return;
		}
		self->capacity = self->length*2; 
		self->array = new_loc;
	}
}

void insert_at(dynamArr* self, int elem, int id)
{
	if (id > self->length || id < 0)
	{
		printf("Invalid index\n");
		return;
	}
	int* new_loc;
        if (self->length >= self->capacity)
        {
                self->capacity *= 2;
                new_loc = realloc(self->array, sizeof(int) * self->capacity);
                if (!new_loc)
                {
                        printf("Memory Allocation Failed\n");
                        self->capacity /= 2;
                        return;
                }
                self->array = new_loc;
        }

	int i;
	for (i = self->length; i > id; i--)
	{
		self->array[i] = self->array[i-1];
	}
	self->array[id] =  elem;
	self->length++;
}


void free_array(dynamArr* self)
{
	if (self != NULL)
	{
		free(self->array);
		free(self);
	}
}

int find_elem(const dynamArr* self, int elem)
{
	int i = 0;
	for(i = 0; i < self->length; i++)
	{
		if (self->array[i] == elem)
		{
			return i;
		}
	}
	return -1;
}
		

