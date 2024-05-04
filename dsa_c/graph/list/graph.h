#include<stdio.h>
#include<stdlib.h>

#include"queue.c"

typedef struct node{

    int verNum;
    int weight;
    struct node* next;
}node;

typedef struct graph{

    int vertices;
    node** arr;

}graph;

void init_graph(graph*,int);
void add_node(graph*,int,int,int);
void display_graph(graph);
void dfs(graph,int,int*);
void bfs(graph,int*,queue*);
int min_index(graph,int*,int*);
graph prims(graph,int);
