#include"heap.h"


void init_max_heap(max_heap* h,int s)
{
    h->capacity=s;
    h->size=0;
    h->arr=(int*)malloc(sizeof(int)*s);
}

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void up_heapify_max_heap(max_heap* h,int i)
{
    while(i>0)
    {
        int parent=(i-1)/2;
        if(h->arr[i]>h->arr[parent])
        {
            swap(&h->arr[i],&h->arr[parent]);

        }
        i=parent;
    }
}

void insert_max_heap(max_heap* h,int val)
{
    if(h->size==0)
    {
        h->arr[h->size]=val;
        h->size++;
        return;
    }

    if(h->size<h->capacity)
    {
        h->arr[h->size]=val;
        up_heapify_max_heap(h,h->size);
        h->size++;
    }
}

void heapify(max_heap* h,int i)
{
    int largest=i;
    int left_child=2*i+1;
    int right_child=2*i+2;

    if(left_child<h->size && h->arr[left_child]>h->arr[largest])
    {
        largest=left_child;
    }
    if(right_child<h->size && h->arr[right_child]>h->arr[largest])
    {
        largest=right_child;
    }

    if(largest!=i)
    {
        swap(&h->arr[i],&h->arr[largest]);
        heapify(h,largest);
    }
}

void delete_max_heap(max_heap* h,int val){

    int i=0;
    for(i=0;i<h->size;i++)
    {
        if(h->arr[i]==val)
        {
            break;
        }
    }
    if(i<h->size)
    {
        swap(&h->arr[i],&h->arr[h->size-1]);
        h->size--;
        for(int j=h->size/2-1;i>=0;i--)
        {
            heapify(h,j);
        }
    }
}

void heap_sort_max_heap(max_heap* h)
{
    int t=h->size;
    int i=1;
    while(i<t)
    {
        swap(&h->arr[0],&h->arr[h->size-1]);
        h->size--;
        for(int j=h->size/2-1;j>=0;j--)
        {
            heapify(h,j);
        }
        i++;
    }
    h->size=t;

}

void print_heap(max_heap h)
{
    for(int i=0;i<h.size;i++)
    {
        printf(" %d ",h.arr[i]);
    }
}