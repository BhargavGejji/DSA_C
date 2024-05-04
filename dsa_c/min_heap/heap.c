#include"heap.h"

void init_min_heap(min_heap* h,int m)
{
    h->capacity=m;
    h->size=0;
    h->arr=(int*)malloc(sizeof(int)*m);
}
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void up_heapify_min_heap(min_heap* h,int i)
{
    
    while(i>0)
    {
        int parent=(i-1)/2;
        if(h->arr[i]<h->arr[parent])
        {
            swap(&h->arr[i],&h->arr[parent]);
        }
        i=parent;
    }
}

void insert_min_heap(min_heap* h,int val)
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

        up_heapify_min_heap(h,h->size);
        h->size++;
    }
    else{
        printf("\n Heap overflow");
    }


}

void down_heapify(min_heap* h, int i) 
{ 
    int left_child=2*i+1;
    int right_child=2*i+2;
    if(left_child>=h->size || right_child>=h->size)
    {
        return;
    }
    if(left_child<h->size && right_child<h->size)
    {
        if(h->arr[i]<h->arr[left_child] && h->arr[i]<h->arr[right_child])
        {
            down_heapify(h,left_child);
            down_heapify(h,right_child);
        }
        else if(h->arr[i]<h->arr[right_child] && h->arr[i]>h->arr[left_child])
        {
            swap(&h->arr[i],&h->arr[left_child]);
            down_heapify(h,left_child);
            down_heapify(h,right_child);
        }
        else if(h->arr[i]>h->arr[right_child] && h->arr[i]<h->arr[left_child])
        {
            swap(&h->arr[i],&h->arr[right_child]);
            down_heapify(h,left_child);
            down_heapify(h,right_child);
        }
        else
        {
            int smallest=(h->arr[left_child]<h->arr[right_child])? h->arr[left_child]: h->arr[right_child];
            swap(&h->arr[i],&smallest);
            down_heapify(h,left_child);
            down_heapify(h,right_child);
        }
        return;
    }
}

void heapify(min_heap* h,int i)
{
    int smallest=i;
    int left_child=2*i+1;
    int right_child=2*i+2;
    if(left_child<h->size && h->arr[left_child]<h->arr[smallest])
    {
        smallest=left_child;
    }
    if(right_child<h->size && h->arr[right_child]<h->arr[smallest])
    {
        smallest=right_child;
    }
    if(smallest!=i)
    {
        swap(&h->arr[i],&h->arr[smallest]);
        heapify(h,smallest);
    }
}

void delete_min_heap(min_heap* h,int val)
{   
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
        for(int i=h->size/2-1;i>=0;i--)
        {
            heapify(h,i);

        }
    }
    
}

int extract_min_min_heap(min_heap* h)
{
    int temp=h->arr[0];
    delete_min_heap(h,temp);
    return temp;
}
void heap_sort(min_heap* h)
{
    int* result=(int*)malloc(sizeof(int)*h->size);
    int t=h->size;
    int i=1;
    int k=0;
    while(i<=t)
    {
        int sm=extract_min_min_heap(h);
        result[k]=sm;
        k++;
        i++;
    }
    for(int j=0;j<t;j++)
    {
        h->arr[j]=result[j];
        h->size++;
    }
    
}

void print_heap(min_heap h)
{
    for(int i=0;i<h.size;i++)
    {
        printf(" %d ",h.arr[i]);
    }
}