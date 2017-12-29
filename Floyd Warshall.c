#include<stdio.h>
#include<limits.h>
#define V 4
void printsolution(int dist[V][V])
{
	int i,j;
	 for (i = 0; i < V; i++)
    {
        for ( j = 0; j < V; j++)
        {
           
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
void floyd(int graph[][V])
{
	int i,j,k;
	int dist[V][V];
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			dist[i][j]=graph[i][j];
			
		}
	}
	for(k=0;k<V;k++)
	{
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	printsolution(dist);
}
int main()
{
  
    int graph[V][V] = { {0,   5,  99, 10},
                        {99, 0,   3, 99},
                        {99, 99, 0,   1},
                        {99, 99, 99, 0}
                      };
 
   
    floyd(graph);
    return 0;
}
