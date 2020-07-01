#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int data[20];
    int front,rear,capacity;
}queue;

queue* createqueue(int value)
{
    queue* node=(queue*)malloc(sizeof(queue));
    node->capacity=value;
    node->front=0;
    node->rear=-1;
}

int isfull(queue* node)
{
    return node->rear==node->capacity-1;
}

int isempty(queue* node)
{
    return node->front==node->rear+1;
}

void insert(queue* node, int element)
{
    if(isfull(node)){
        printf("The Queue is Full");
    }
    else{
        node->data[++(node->rear)]=element;
    }
}

int deletee(queue* node)
{
    if(isempty(node)){
        printf("The Queue is Empty");
    }
    else{
        int temp=node->data[node->front];
        node->data[node->front]=node->data[node->front++];
        return temp;
    }
}

void reverse(queue* node,queue* rev,int n){
    for(int i=0;i<n;i=i+1){
        insert(rev,node->data[node->rear--]);
    } 
}

int main()
{
    int n,*arr;

    printf("Enter the number of elements");
    scanf("%d",&n);
    
    queue* node=createqueue(23);
    queue* rev=createqueue(23);
    arr=(int*)malloc(sizeof(int)*n);
    
    printf("Enter the elements of the array");
    for(int i=0;i<n;i=i+1){
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<n;i=i+1){
        insert(node,arr[i]);
    }

    reverse(node,rev,n);

    for(int i=0;i<n;i=i+1){
        printf("%d ", deletee(rev));
    }

return 0;
}