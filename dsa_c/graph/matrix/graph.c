#include"graph.h"

void init(graph* g,int v)
{
    g->vertices=v;
    g->arr=(int**)malloc(sizeof(int*)*v);
    for(int i=0;i<v;i++)
    {
        g->arr[i]=(int*)malloc(sizeof(int)*v);
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            g->arr[i][j]=0;
        }
    }
}//end of init_function

void addNode(graph* g,int src,int dest,int weight)
{
    if(src>=0 && src<g->vertices)
    {
        if(dest>=0 && dest<g->vertices){

            g->arr[src][dest]=weight;
            g->arr[dest][src]=weight;

        }
    }
    
}

void display_graph(graph g)
{
    for(int i=0;i<g.vertices;i++)
    {
        for(int j=0;j<g.vertices;j++)
        {
            printf("%d ", g.arr[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}


void removeNode(graph* g,int src,int dest)
{
    if(src>=0 && src<g->vertices)
    {
        if(dest>=0 && dest<g->vertices)
        {
             g->arr[src][dest]=0;
             g->arr[dest][src]=0;


        }
    }
   
}

int isAdjacent(graph g,int src,int dest)
{
    if(g.arr[src][dest]!=0)
    {
        return 1;
    }
    return 0;
}

void dfs(graph g,int i,int visited[])
{
    printf("%d ",i);
    
    visited[i]=1;
    for(int j=0;j<g.vertices;j++)
    {
        if(g.arr[i][j]!=0 && !visited[j])
        {
            dfs(g,j,visited);
        }
    }

}//end of dfs function

void bfs(graph g,int visited[],queue* q)
{
    while(!isEmpty(q))
    {
        int node=dequeue(q);
        for(int i=0;i<g.vertices;i++)
        {
            if(g.arr[node][i]!=0 && !visited[i])
            {
                printf("%d ",i);
                visited[i]=1;
                enqueue(q,i);
            }
        }
    }
}

int isConnected(graph g)
{
    int* visited=(int*)malloc(sizeof(int)*g.vertices);
    // Initialize visited array to all zeros
    for (int i = 0; i < g.vertices; i++) {
        visited[i] = 0;
    }
    dfs(g,0,visited);
    for(int i=0;i<g.vertices;i++)
    {
        if(visited[i]==0)
            return 0;
    }
    return 1;
}

int degree(graph g,int vernum)
{
    if(vernum>=0 && vernum<g.vertices)
    {
        int deg=0;
        for(int i=0;i<g.vertices;i++)
        {
            if(g.arr[vernum][i]!=0)
            {
                deg++;
            }
        }
        return deg;
    }
    return -1;
    
}

int min_key(graph g,int* key,int* mst)
{
    int min=INT_MAX;
    int min_idx=INT_MAX;
    for(int i=0;i<g.vertices;i++)
    {
        if(mst[i]==0 && key[i]<min)
        {
            min=key[i];
            min_idx=i;
        }
    }
    return min_idx;
}

graph prims(graph* g)
{
	int* key;
	int* mst;
	int* parent;
	int n=g->vertices;
    key=(int*)malloc(sizeof(int)*n);
    mst=(int*)malloc(sizeof(int)*n);
    parent=(int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mst[i]=0;
    }

    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<n-1;count++)
    {
        int temp=min_key(*g,key,mst);
        mst[temp]=1;
        for(int i=0;i<n;i++)
        {
            if(g->arr[temp][i]!=0 && mst[i]==0 && g->arr[temp][i]<key[i])
            {
                parent[i]=temp;
                key[i]=g->arr[temp][i];
            } 
        }
    }

    //building the mst;
    graph mt;
    init(&mt,n);
    for(int i=1;i<n;i++)
    {
        int t=parent[i];
        addNode(&mt,i,t,key[i]);

    }
    return mt;

}


