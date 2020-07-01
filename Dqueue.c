#include<stdio.h>
#include<stdlib.h>

typedef struct dqueue
{
    int data[20];
    int capacity;
    int front;
    int rear;
}dqueue;

dqueue* createdqueue(int value)
{
    dqueue* node=(dqueue*)malloc(sizeof(dqueue));
    node->capacity=value;
    node->front=0;//Start Both From The Same Values
    node->rear=0;
}

//This Will Insert The Elements From The Front 
void insertFront(dqueue* node,int element)
{
    node->data[--(node->front)]=element;
}

//This Will Insert The Elements From The Rear
void insertRear(dqueue* node,int element)
{
    node->data[++(node->rear)]=element;
}

//This Will Delete The Elements From The Front
int deleteFront(dqueue* node)
{
    if(node->front<=0){
        int temp=node->data[node->front];
        node->data[node->front]=node->data[node->front++];
        return temp;
    }
}

//This Will Delete The Elements From The Rear
int deleteRear(dqueue* node)
{
    if(node->rear>0){
        int temp=node->data[node->rear];
        node->data[node->rear]=node->data[--(node->rear)];
        return temp;
    }
}

int main()
{
    dqueue* node=createdqueue(23);
    insertFront(node,1);
    insertFront(node,2);
    insertFront(node,3);
    insertRear(node,4);
    insertRear(node,5);
    insertRear(node,6);
    insertRear(node,7);
    printf("%d ",deleteFront(node));
    printf("%d ",deleteFront(node));
    printf("%d ",deleteFront(node));
    printf("%d ",deleteRear(node));
    printf("%d ",deleteRear(node));
    printf("%d ",deleteRear(node));
    printf("%d ",deleteRear(node));
    return 0;
}