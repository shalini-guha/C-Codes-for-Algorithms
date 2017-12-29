#include<stdio.h>
#define V 4
int front=0,rear=0,queue[V];
void push(int m){
queue[rear++]=m;
}
int pop(){
    int c=queue[front];
    front++;
    return c;
}
int traversed(int u,int n,int visited[V]){
    int i;
    for(i=0;i<n;i++){
        if(visited[i]==u)
            return 0;
    }
    return 1;
}
void bfs(int graph[V][V],int src){
    int visited[V];
    int c=0,i,u,l;
   push(src);
while(c<V){
     u=pop();
    visited[c++]=u;
    for(i=0;i<V;i++){
         l=graph[u][i];
        if(traversed(i,c,visited)==1 && l==1)
            push(i);
    }
}
                     printf("Printed");
                     for(i=0;i<V;i++)
                        printf("%d",visited[i]);
                      
}

int main(){
    int i;
     int graph[V][V] = {
         {0,1,1,0},
         {0,0,1,0},
         {1,0,0,1},
         {0,0,0,1}
     };

                     bfs(graph,2);

}
