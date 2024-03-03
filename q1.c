#include<stdio.h>
void insertion(int arr[],int length){
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
            else{
                break;
            }

        }

    }


}

int main(){
    int arr[]={5,3,2,7,1};
    int length=sizeof(arr)/sizeof(int);
    insertion(arr,length);

    for(int i=0;i<length;i++){
        printf("%d\n",arr[i]);
    }
    }
