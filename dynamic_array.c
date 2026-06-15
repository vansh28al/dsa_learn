#include<std.h>
#include<stdlib.h>

typedef struct 
{
	int capacity;
	int length;
	int* array;
}  dynamArr;

dynamArr* arrCreate(int cap, int len)
{
	dynamArr* r = (dynamArr*)malloc(sizeof(Rectangle));
	if (r != NULL)
	{
		r->capacity = cap;
		r->length = len;
		r->array = malloc(sizeof(int)*cap);
	}

	return r;
}


