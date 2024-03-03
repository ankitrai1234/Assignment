#include<stdio.h>
int  getMaxIndex(int arr[],int start,int end){
    int max = start;
        for (int i = start; i <= end; i++) {
            if (arr[max] < arr[i]) {
                max = i;
            }
        }
        return max;

    }

void selection(int arr[],int length){
          for (int i = 0; i < length; i++) {
            // find the max item in the remaining array and swap with correct index
            int last = length - i - 1;
            int maxIndex = getMaxIndex(arr, 0, last);
            int temp=arr[maxIndex];
            arr[maxIndex]=arr[last];
            arr[last]=temp;
        }
    }
int main(){
    int arr[]={5,3,2,7,1};
    int length=sizeof(arr)/sizeof(int);
    selection(arr,length);

    for(int i=0;i<length;i++){
        printf("%d\n",arr[i]);
    }
    }

