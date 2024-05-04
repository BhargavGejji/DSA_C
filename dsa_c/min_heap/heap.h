#include<stdio.h>
#include<stdlib.h>

typedef struct min_heap{
    int capacity;
    int size;
    int* arr;
}min_heap;

void init_min_heap(min_heap* h,int m);
void insert_min_heap(min_heap* h,int val);
void delete_min_heap(min_heap* h,int val);
void heap_sort(min_heap* h);