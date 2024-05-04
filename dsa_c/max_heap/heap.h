#include<stdio.h>
#include<stdlib.h>

typedef struct max_heap{

    int capacity;
    int size;
    int* arr;

}max_heap;

void init_max_heap(max_heap* h,int s);
void insert_max_heap(max_heap* h,int val);
void delete_max_heap(max_heap* h,int val);
void heap_sort_max_heap(max_heap* h);
void print_heap(max_heap h);

