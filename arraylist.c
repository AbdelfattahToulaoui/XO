#include <stdlib.h>
#include "arraylist.h"

// append an element to the list
void append(arraylist * a, int i)
{
    // increment the size member
    a->size++;
    // using 'realloc' to provide sufficient memory
    // for all list elements
    a->inti = realloc(a->inti, a->size * sizeof(int));
    // now append the element
    a->inti[a->size - 1] = i;
}

// clear the arraylist
void clear(arraylist * a)
{
    a->size = 0;
    if (a->inti != NULL) {
	// free unused memory
	free(a->inti);
	// setting the pointer to NULL to avoid 'double free'
	a->inti = NULL;
    }
}

// create a new arraylist
arraylist *newarraylist()
{
    arraylist *a = malloc(sizeof(arraylist));
    a->size = 0;
    return a;
}
