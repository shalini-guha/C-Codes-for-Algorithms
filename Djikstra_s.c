#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define V 9
int mindistance(int dist[],int sptset[])
{
	int min=INT_MAX,i,u,minvalue;
	for(i=0;i<V;i++)
	{
		if(sptset[i]==0 && dist[i]<=min)
		{
		min=dist[i];
		minvalue=i;
		}
	}
	return minvalue;
}
void printsolution(int dist[],int v)
{
	int i;
	for(i=0;i<v;i++)
	{
		printf("%d\t",dist[i]);
	}
}
void dijkstra(int graph[V][V],int src)
{
	int v=0,u=0,count=0;
	int dist[V];
	int sptset[V];
	for(v=0;v<V;v++)
	{
		dist[v]=INT_MAX;
		sptset[v]=0;
	}
	dist[src]=0;
	for(v=0;v<V-1;v++)
	{
		u=mindistance(dist,sptset);
		sptset[u]=1;
		for(count=0;count<V;count++)
		{
			if(sptset[count]==0 && graph[u][count] && dist[u]!=INT_MAX && (dist[u]+graph[u][count]<dist[count]))
			{
			dist[count]=dist[u]+graph[u][count];
			}
		}
	}
		
	
	printsolution(dist,V);
}


int main()
{

   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
