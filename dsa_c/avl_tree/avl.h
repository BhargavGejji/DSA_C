#include<stdio.h>
#include<stdlib.h>


typedef struct node{

    int data;
    int balance_factor;
    struct node* parent;
    struct node* left;
    struct node* right;


}node;
typedef node* avl;

void init_avl(avl*);
void insert_avl(avl*,int);
node* delete_avl(avl*,node*,int);
void adjust_bf(avl*);
void adjust_imbalance(avl* ,node*);
void ll(avl*,node*);
void rr(avl*,node*);
void lr(avl*,node*);
void rl(avl*,node*);
void inorder_print(avl);
