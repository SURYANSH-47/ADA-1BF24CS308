#include<stdio.h>
    int n;
int dist[20][20];
int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
void floyd(int cost[][20]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=cost[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix: ");
    int cost[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    floyd(cost);
    printf("The distance matrix is: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("The minimum distance between %d to %d is %d\n",i,j,dist[i][j]);
        }
    }
    return 0;

}