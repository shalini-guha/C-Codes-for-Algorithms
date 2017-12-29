#include<stdio.h>
#define V 4

int isSafe(int color[],int graph[V][V],int c,int v)
{
	int i;
	for(i=0;i<V;i++)
	if(graph[v][i] && c==color[i])
		return 0;
		return 1;
	
}
void printsolution(int color[])
{	int i;
    printf("Solution Exists:"
            " Following are the assigned colors \n");
    for ( i = 0; i < V; i++)
      printf(" %d ", color[i]);
    printf("\n");
}
int graphUtil(int graph[V][V],int color[],int m,int v)
{	int c;
	if(v==V)
	return 1;
	for(c=1;c<=m;c++)
	{
		if(isSafe(color,graph,c,v)==1)
		{
			
			color[v]=c;
			if(graphUtil(graph,color,m,v+1)==1)
			return 1;
		
			color[v]=0;		
		}
		
	}
	return 0;
}
int graphCol(int graph[V][V],int m)
{
	int color[V];
	int c,i,j;
	for(i=0;i<V;i++)
	{
		color[i]=0;
	}
	if(graphUtil(graph,color,m,0)==0)
	{
		printf("\n Solution does not exist");
		return 0;
	}

		printsolution(color);
	
}
int main()
{
   int m = 3;
   int graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
   
    graphCol(graph, m);
    return 0;
}
