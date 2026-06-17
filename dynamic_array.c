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
	dynamArr* r = (dynamArr*)malloc(sizeof(dynamArr));
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

void del(dynamArr* self, int id)
{
	if (id < 0 || id >= self->length)
        {
                printf("Invalid Index");
                return;
        }

	if (self->length == 1)
	{
		free(self->array);
		self->array = NULL;
		self->length = 0;
		self->capacity = 0;
		printf("Array deleted");
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
			printf("Memory Reallocation failed");
			return;
		}
		self->capacity = self->length*2; 
		self->array = new_loc;
	}
}

void insert_at(dynamArr* self, int elem, int id)
{
	if (id >= self->length)
	{
		printf("Invalid index");
		return;
	}
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
		self->array = NULL;
		self->length = 0;
		self->capacity = 0;
	}
}

int find_elem(dynamArr* self, int elem)
{
	int found = 0;
	int i = -1;
	while ((i < self->length) & !found)
	{
		i++;
		if (self->array[i] == elem)
		{
			found = 1;
		}
	}
	return i;
}
		

