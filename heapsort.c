#include<stdio.h>
void heapc(int arr[],int n){
    int i,j,k,item;
    for(k=0;k<n;k++){
        item=arr[k];
        i=k;j=(i-1)/2;
        while(i>0&&item>arr[j]){
            arr[i]=arr[j];
            i=j;
            j=(i-1)/2;
        }
        arr[i]=item;
    }
}
void heapa(int arr[],int n){
    int i,j,item;
    j=0;item=arr[j];
    i=2*j+1;
    while(i<=n-1){
        if(i+1<=n-1){
            if(arr[i]<arr[i+1])
            i++;
        
        }
        if(item<arr[i]){
            arr[j]=arr[i];
            j=i;
            i=2*j+1;
        }
        else 
        break;
    }
    arr[j]=item;
}
void heapsort(int arr[],int n){
    int i,temp;
    heapc(arr,n);
    for(int i=n-1;i>0;i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapa(arr,i);
    }
}
int main(){
    int arr[10];int n;
    printf("Enter the size of the elements: ");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    printf("The sorted array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}