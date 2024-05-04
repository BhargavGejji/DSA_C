#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct tree{
    int* arr;
    
    int size;

}tree;

void tinit(tree*,int);
void insert_bst(tree*,int);
void print_inorder(tree);
void print_postorder(tree);
void print_preorder(tree);
int is_complete(tree);
void print_levelwise(tree);
