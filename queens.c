#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int board[10];
int place(int row,int column){
    int j;int flag=1;
    for(j=1;j<row;j++){
        if(board[j]==column||(abs(board[j]-column)==abs(j-row))){flag=0;}
    }
    return flag;
}
void print(int n){
    printf("SOLUTION\n");
    for(int i=1;i<=n;i++){
        printf("%d\n",board[i]);
    }
}
void queens(int row,int n){
    int j;
    for(j=1;j<=n;j++){
        if(place(row,j)==1){
            board[row]=j;
            if(row==n){print(n);}
            else{
                queens(row+1,n);
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the number of queens:  ");
    scanf("%d",&n);
    queens(1,n);
    return 0;
}