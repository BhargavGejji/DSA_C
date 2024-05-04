#include"graph.c"


int main()
{
	graph g;
	printf("\nEnter the number of vertices ");
	int n=0;
	scanf("%d",&n);
	init_graph(&g,n);
	 add_node(&g,0,1,3);
    add_node(&g,0,3,7);
    add_node(&g,0,4,8);
    add_node(&g,1,2,1);
	 add_node(&g,1,3,4);
    add_node(&g,3,2,2);
    add_node(&g,4,3,3);
   
	printf("\nThe graph is as follows\n");
	display_graph(g);
	printf("\n");
	printf("dfs: ");

	
	int* visited=(int*)malloc(sizeof(int)*g.vertices);
	for(int i=0;i<g.vertices;i++)
	{
		visited[i]=0;
	}
	dfs(g,0,visited);
	printf("\n");
	printf("bfs: ");
	for(int i=0;i<g.vertices;i++)
	{
		visited[i]=0;
	}
	
	queue q;
	q.size=400;
	q.f=q.r=0;
	q.arr=(int*)malloc(sizeof(int)*q.size);
	//dfs(g,4,visited);
	int i=0;
	printf("%d ",i);
	enqueue(&q,i);
	visited[i]=1;
	bfs(g,visited,&q);
	// printf("\n");
	// printf("Minimum spanning tree: ");
	// printf("\n");
	// graph mst=prims(g,0);
	// display_graph(mst);
	
	
	return 0;
}
