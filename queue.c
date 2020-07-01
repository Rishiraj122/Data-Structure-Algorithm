#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int data[20];
    int front;
    int rear;
    int capacity;
}queue;

queue* createqueue(int value)
{
    queue* node=(queue*)malloc(sizeof(queue));
    node->capacity=value;
    node->front=0;
    node->rear=-1;
}

int isqueuefull(queue* node)
{
    return node->rear==node->capacity-1;
}

int isqueueempty(queue* node)
{
    return  node->front==node->rear+1;
}

void insert(queue* node, int element)
{
    if(isqueuefull(node)){
        printf("The Queue is Full");
    }
    else{
        node->data[++(node->rear)]=element;
    }
    
}

int deletee(queue* node)
{
    if(isqueueempty(node)){
        printf("The Queue is Empty");
    }
    else{
        int temp;
        temp=node->data[node->front];
        node->data[node->front]=node->data[node->front++];
        return temp;
    }
}

int main()
{
    queue* q=createqueue(20);
    insert(q,23);
    insert(q,34);
    insert(q,12);
    insert(q,120);
    printf("%d\n",deletee(q));
    printf("%d\n",deletee(q));
    printf("%d\n",deletee(q));
    printf("%d\n",deletee(q));

    return 0;
}