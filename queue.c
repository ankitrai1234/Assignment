#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
    };
int isempty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
    }
int isfull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
    }
void push(struct queue *q,int n){
    if(isfull(q)){
        printf("queue overflow no other element can be inserted");
    }
    q->r++;
    q->arr[q->r]=n;
    }
int pop(struct queue *q){
    if(isempty(q)){
        printf("The queue is empty no elements can be inserted ");
        return -1;
    }
    q->f++;
    int n=q->arr[q->f];

    return n;
}
void traverse(struct queue *q) {
    if (isempty(q)) {
        printf("The queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->f + 1; i <= q->r; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main(){
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->f=q->r=-1;
    q->size=10;
    q->arr=(int *)malloc(q->size*sizeof(int));
    push(q,60);
    push(q,70);
    int x=pop(q);
    printf("%d\n",x);
    traverse(q);
    return 0;

}

