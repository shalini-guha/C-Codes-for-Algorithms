#include<stdio.h>
#define V 4
int top=-1,stack[V];
void push(int m){
stack[++top]=m;
}
int pop(){
    int c=stack[top];
    --top;
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
void dfs(int graph[V][V],int src){
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
                     for(i=0;i<V;i++)
                        printf("%d",visited[i]);
                        return 0;
}
int main(){
    int i;
//     int graph[V][V] = {
//         {0,1,1,1,1,0,0,0},
//         {1,0,0,0,0,1,0,0},
//         {1,0,0,0,0,1,0,0},
//         {1,0,0,0,0,0,1,0},
//         {1,0,0,0,0,0,1,0},
//         {0,1,1,0,0,0,0,1},
//         {0,0,0,1,1,0,0,1},
//         {0,0,0,0,0,1,1,0}
//     };
int graph[V][V] = {
         {0,1,1,0},
         {0,0,1,0},
         {1,0,0,1},
         {0,0,0,1}
     };


                     dfs(graph,3);

}
