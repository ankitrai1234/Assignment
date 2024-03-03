#include<stdio.h>
int sequencialsearch(int arr[],int a,int len){
    for(int i=0;i<len;i++){
        if(arr[i]==a){
            return i;
        }
    }
    return -1;

}
int main(){
    int arr[6];
    int a;
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        scanf("%d",&arr[i]);

    }
    printf("Enter the number to be searched");
    scanf("%d",&a);
    int b=sequencialsearch(arr,a,sizeof(arr)/sizeof(int));
    if(b!=-1){
        printf("%d found at index %d",a,b);
    }
    else if(b==-1){
        printf("element not found");
    }
    return 0;
}
