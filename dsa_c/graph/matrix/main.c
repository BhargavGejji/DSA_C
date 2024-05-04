#include"graph.c"


int main()
{
    graph g;
    printf("Enter the number of vertices\n");
    int n=0;
    scanf("%d",&n);
    init(&g,n);
    addNode(&g,0,1,3);
    addNode(&g,0,3,7);
    addNode(&g,0,4,8);
    addNode(&g,1,2,1);
    addNode(&g,3,2,2);
    addNode(&g,4,3,3);
    addNode(&g,1,3,4);
    // display_graph(g);
    
    
    // int *visited=(int*)malloc(sizeof(int)*g.vertices);
    
    // for(int i=0;i<g.vertices;i++)
    // {
    //     visited[i]=0;
        
    // }

    // dfs(g,0,visited);
    // queue q;
    // q.size=400;
    // q.f=q.r=0;
    // q.arr=(int*)malloc(sizeof(int)*q.size);
    // for(int i=0;i<g.vertices;i++)
    // {
    //     visited[i]=0;

    // }
    // //bfs implementation

    // int i=0;
    // printf("%d ",i);
    // visited[i]=1;
    // enqueue(&q,i);
    // bfs(g,visited,&q);
    graph mst=prims(&g);
    display_graph(mst);
    return 0;
}