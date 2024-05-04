#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int* arr;
}queue;

int isEmpty(queue* q)
{
    if(q->r==q->f)
        return 1;
    
    return 0;
}

int isFull(queue* q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;

}

void enqueue(queue* q,int val)
{
    if(isFull(q))
    {
        printf("\nThe Queue is full\n");
        return;
    }

    q->r++;
    q->arr[q->r]=val;
    
}

int dequeue(queue* q)
{
    if(isEmpty(q))
    {
        printf("\nThe Queue is empty\n");
        return INT_MIN;

    }
    int a=-1;
    q->f++;
    a=q->arr[q->f];
    return a;
}