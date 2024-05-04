#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;

}node;
typedef struct node_list{

    node* data;
    struct node_list* next;
}node_list;

typedef node_list* list;


typedef struct stack{

    list head;

}stack;

void init_stack(stack* s)
{
    s->head=NULL;
}

void push(stack* s, node* val)
{
    node_list* nn=(node_list*)malloc(sizeof(node_list));
    if(nn)
    {
        nn->data=val;
        nn->next=NULL;
    }

    if(s->head==NULL)
    {
        s->head=nn;
        return;
    }
    nn->next=s->head;
    s->head=nn;
    return;
}

node* pop(stack* s)
{
    if(s->head==NULL)   
        return INT_MIN;

    if(s->head->next==NULL)
    {
        node_list* temp=s->head;
        s->head=NULL;
        node* a=temp->data;
        free(temp);
        return a;
    }

    node_list* temp=s->head;
    s->head=(s->head)->next;
    node* a=temp->data;
    free(temp);
    return a;
    
}

int isEmptyStack(stack s)
{
    if(s.head==NULL)
        return 1;
    return 0;
}