#include"graph.h"

void init_graph(graph* g,int v)
{
	g->vertices=v;
	g->arr=(node**)malloc(sizeof(node*)*v);
	for(int i=0;i<v;i++)
	{
		g->arr[i]=NULL;
	}
	
}

void add_node(graph* g,int s,int d,int w)
{
   node* src=(node*)malloc(sizeof(node));
   if(src)
   {
    src->next=NULL;
    src->verNum=s;
    src->weight=w;
   }
   
   node* dest=(node*)malloc(sizeof(node));
   if(dest)
   {
    dest->next=NULL;
    dest->verNum=d;
    dest->weight=w;
   }

   if(g->arr[s]==NULL)
   {
    g->arr[s]=dest;
    
   }
   else
   {
    node* temp=g->arr[s];
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=dest;
   }


   if(g->arr[d]==NULL)
   {
    g->arr[d]=src;
   }
   else{
    node* temp=g->arr[d];
    while(temp->next){
        temp=temp->next;
    }
    temp->next=src;
   }
}


void display_graph(graph g)
{
	for(int i=0;i<g.vertices;i++)
	{
		node* p=g.arr[i];
		printf("%d-> ",i);
		while(p)
		{
			printf("%d ",p->verNum);
			p=p->next;
		}
		printf("\n");
	}
}

void dfs(graph g,int i,int visited[])
{
	printf("%d ",i);
	visited[i]=1;
	node* p=g.arr[i];
	
	while(p)
	{
		if(!visited[p->verNum])
		{
			dfs(g,p->verNum,visited);
		}
		p=p->next;
	}
	
}

void bfs(graph g,int visited[],queue* q)
{

	while(!isEmpty(q))
	{
		int n=dequeue(q);
		node* m=g.arr[n];
		
		while(m)
		{
			if(!visited[m->verNum])
			{
				printf("%d ",m->verNum);
				enqueue(q,m->verNum);
				visited[m->verNum]=1;
			}
			m=m->next;
		}
	}
	
}


int min_index(graph g,int * visited,int* key){
    int min=INT_MAX;
    int index=-1;
    for(int i=0;i<g.vertices;i++){
        if(!visited[i] && min>key[i]){
            index=i;
            min=key[i];
        }
    }
    return index;
}

graph prims(graph g,int start){
    graph min;
    init_graph(&min,g.vertices);
    int *visited=(int*)malloc(sizeof(int)*g.vertices);
    int *key=(int*)malloc(sizeof(int)*g.vertices);
    int *parent=(int*)malloc(sizeof(int)*g.vertices);
    for(int i=0;i<g.vertices;i++){
        key[i]=INT_MAX;
        visited[i]=0;
    }
    key[start]=0;
    parent[start]=0;
    for(int i=0;i<g.vertices;i++){
        int u=min_index(g,visited,key);
        visited[u]=1;
        node* p=g.arr[u];
        while(p){
            if(!visited[p->verNum] && p->weight<key[p->verNum]){
                parent[p->verNum]=u;
                key[p->verNum]=p->weight;
            }
            p=p->next;
        }
    }
    for(int i=0;i<g.vertices;i++){
        if(i==start) continue;
        node* p=g.arr[i];
        while(p && p->verNum!=parent[i]) p=p->next;
        add_node(&min,i,parent[i],p->weight);
    }
    return min;
}


