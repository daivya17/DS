#include<stdio.h>
#include<conio.h>
int adj[10][10];
int n;
int vis[10];
void bfs(int v){
    int q[10],rear=1,front=1,u;
    vis[v] = 1;
    q[rear] = v;
    while(front<=rear){
        u = q[front];
        printf("%d ",u);
        for(int i=1;i<=n;i++){
            if(adj[u][i]==1 && vis[i]==0){
                vis[i] = 1;
                rear++;
                q[rear] = i;
            }
        }
        front++;
    }
}
int main(){
    printf("enter no of vertices:");
    scanf("%d",&n);
    printf("enter adjacency matrix:");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
        vis[i] = 0;
    }
    int v;
    printf("enter node to start traversing:");
    scanf("%d",&v);
    bfs(v);
}
