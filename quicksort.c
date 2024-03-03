#include<stdio.h>
void sort(int nums[],int low,int high){
    if(low>=high){
        return;
    }
    int s=low;
    int e=high;
    int m=s+(e-s)/2;
    int pivot=nums[m];
    while(s<=e){
        while(nums[s]<pivot){
            s++;
        }
        while(nums[e]>pivot){
            e--;
        }
        if(s<=e){
            int temp=nums[s];
            nums[s]=nums[e];
            nums[e]=temp;
            s++;
            e--;
        }


    }
    sort(nums,low,e);
    sort(nums,s,high);


    }
int main(){
    int nums[]={5,3,2,4,1};
    sort(nums,0,sizeof(nums)/sizeof(int)-1);
    for(int i=0;i<sizeof(nums)/sizeof(int);i++){
        printf("%d\n",nums[i]);
    }
    return 0;

}



