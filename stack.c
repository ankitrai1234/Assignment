#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int head;
    int *arr;
};
int isempty(struct stack *p){
    if(p->head==-1){
        return 1;
    }
    else{
        return 0;
    }
 }
 int isfull(struct stack *p){
       if(p->head==p->size-1){
        return 1;
       }
       else{
        return 0;
       }
        }
void push(struct stack *p,int n){
    if(isfull(p)){
        printf("Stack Overflow no element can be inserted");
        return;
    }
    else{
        p->head=p->head+1;
        p->arr[p->head]=n;

    }

    }
int pop(struct stack *p){
    if(isempty(p)){
        printf("Stack Underflow Stack already empty");
        return -1;
    }
    int n=p->arr[p->head];
    p->head=p->head-1;
    return n;
    }


int main(){
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size=60;
    s->head=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    push(s,30);
    push(s,60);
    push(s,50);
    int x=pop(s);
    printf("%d",x);
    return 0;
        }
