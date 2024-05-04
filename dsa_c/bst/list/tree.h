#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"stack.c"


typedef node* tree;

void init(tree*);
node* new_node(int);
void insert_bst(tree*,int );
int search(tree,int);
void print_inorder(tree);
void print_preorder(tree);
void print_postorder(tree);


int count(tree);
int height(tree);

void print_inorder_nonrecursive(tree t);
void print_postorder_nonrecursive(tree t);
void print_preorder_nonrecursive(tree t);