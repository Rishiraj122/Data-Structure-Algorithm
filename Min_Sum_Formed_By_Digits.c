#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int *a ,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

typedef struct queue
{
    int data[20];
    int capacity;
    int front;
    int rear;
}queue;

queue* createqueue(int value)
{
    queue* node=(queue*)malloc(sizeof(queue));
    node->capacity=value;
    node->front=0;
    node->rear=-1;
    return node;
}

int isfull(queue* node)
{
    return node->rear==node->capacity-1;
}

int isempty(queue* node)
{
    return node->front==node->rear+1;
}

void insert(queue* node,int value)
{
    if(isfull(node)){

    }
    else{
        node->data[++(node->rear)]=value;
    }
}

int deletee(queue* node)
{
    if(isempty(node)){

    }
    else{
        int temp;
        temp=node->data[node->front];
        node->data[node->front]=node->data[node->front++];
        return temp;
    }
}

int partition(int arr[],int low,int high)
{
    int i=low-1;
    int pivot=arr[high];

    for(int j=low;j<=high;j=j+1){
        if(arr[j]<pivot){
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quickSort(int arr[],int low,int high)
{
    if(low<high){
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main()
{
    int testcase=0;
    
    scanf("%d",&testcase);

    while(testcase>0){
        int n,*arr,*a,*b,x=0,y=0,sum=0,num1=0,num2=0;

    printf("Enter The Size of The Digit List ");
    scanf("%d",&n);
    queue* node=createqueue(n);

    arr=(int*)malloc(sizeof(int)*n);
    a=(int*)malloc(sizeof(int)*n);
    b=(int*)malloc(sizeof(int)*n);

    printf("Enter The Elements ");

    for(int i=0;i<n;i=i+1){
        scanf("%d",&arr[i]);
    }

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i=i+1){
        insert(node,arr[i]);
    }

    for(int k=1;k<=n;k=k+1){
        if(k%2!=0){
            b[x]=deletee(node);
            x=x+1;
        }
        else{
            a[y]=deletee(node);
            y=y+1;
        }
    }

    for(int i=0;i<x;i=i+1){
        num1=num1*10+b[i];
    }

    for(int i=0;i<y;i=i+1){
        num2=num2*10+a[i];
    }

    sum=num1+num2;
    printf("%d\n",sum);

    testcase=testcase-1;
    }

return 0;
}
