#include<stdio.h>
#include<stdlib.h>
#include"queue.c"
typedef struct graph{

    int** arr;
    int vertices;
}graph;


void init(graph*,int);
void addNode(graph* g,int,int,int);
void removeNode(graph*,int,int);
void display(graph);
void dfs(graph,int,int*);
int isAdjacent(graph,int,int);
void bfs(graph g,int*,queue*);
int isConnected(graph);
int degree(graph,int);

