#ifndef ARRAYLIST_H
#define ARRAYLIST_H

struct arraylist{
    int size;
    int * inti;
} typedef arraylist;


void append(arraylist *a, int i);

void clear(arraylist *a);

arraylist *newarraylist();

#endif
