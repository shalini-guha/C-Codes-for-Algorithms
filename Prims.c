#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>
#define V 9
int mindistance1(int key[],int mstset[])
{
	int i,min,u;
	min=INT_MAX;
	for(i=0;i<V;i++)
	{
		if(mstset[i]==0&&key[i]<min)
		{
			min=key[i];
			u=i;
		}
	}
	return u;
}
void printsolution1(int parent[],int n,int graph[V][V])
{
	int i;
	printf("Edge   Weight\n");
	for(i=1;i<V;i++)
	{
	printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
	}
}
void prim(int graph[V][V])
{
	int key[10];
	int parent[10];
	int mstset[10];
	int i,v,u=0,count; 
	for(i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		mstset[i]=0;
	} 
	key[0]=0;
	parent[0] = -1;
	for(v=0;v<V -1;v++)
	{  
		u=mindistance1(key,mstset);
		mstset[u]=1;
		for(count=0;count<V;count++)
		{ 
			if(graph[u][count]&&mstset[count]==0&&graph[u][count]<key[count])
			{ 
			parent[count]=u;
			key[count]=graph[u][count];
			}
		}
	}  
	printsolution1(parent,V,graph);
}
int main()
{
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    prim(graph);
 
    return 0;
}
