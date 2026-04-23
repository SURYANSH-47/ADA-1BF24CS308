#include<stdio.h>
int n;
    int cost[20][20];
int dest[10],vis[10];
void dij(int src){
    int i,min,count;
    for(int i=0;i<n;i++){
        dest[i]=cost[src][i];
    }
    vis[src]=1;
    count =1;int u;
    while(count<n){
        min=999;
        for(int i=0;i<n;i++){
            if(dest[i]<min&&vis[i]==0){
                min=dest[i];
                u=i;
            }
        }
        vis[u]=1;
        for(int i=0;i<n;i++){
            if((dest[u]+cost[u][i])<dest[i]&&vis[i]==0){
                dest[i]=dest[u]+cost[u][i];
            }
        }
                count++;

    }
}
int main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    int p;
    scanf("%d",&p);
    dij(p);
    printf("Shortest path is: ");
    for(int i=0;i<n;i++){
        printf("\n%d-->%d=%d",p,i,dest[i]);
    }
    return 0;

}