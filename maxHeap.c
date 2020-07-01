#include<stdio.h>
#include<stdlib.h>

typedef struct maxheap
{
    int data;
    struct maxheap* left;
    struct maxheap* right;
}maxheap;

maxheap* createheap(int value)
{
    maxheap* max=(maxheap*)malloc(sizeof(maxheap));
    max->data=value;
    max->left=max->right=NULL;
    return max;
}

void swap(int *a, int *b){
    int l=*a;
    *a=*b;
    *b=l;
}

void heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }

    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }

    if(largest!=i){
        swap(&arr[i], &arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildheap(int arr[],int n){
    int nonLeaf=(n/2)-1;
    for(int i=nonLeaf;i>=0;i--){
        heapify(arr,n,i);
    }
}

void printing(int arr[],int n)
{
    for(int i=0;i<n;i=i+1){
        printf("%d ",arr[i]);
    }
}

void printInorder(maxheap* max)
{
    if(max!=NULL){
        printInorder(max->left);
        printf("%d ",max->data);
        printInorder(max->right);
    }
}

//Converts The Array Into The Tree In Level Order
maxheap* insertLevelOrder(int arr[],maxheap* max,int i,int n)
{
    if(i<n){
        maxheap* tempmax=createheap(arr[i]);
        max=tempmax;
        max->left=insertLevelOrder(arr,max->left,2*i+1,n);
        max->right=insertLevelOrder(arr,max->right,2*i+2,n);
    }
    return max;
}

int main()
{
    int n,k;
    printf("Enter Elements Total Number");
    scanf("%d",&n);
    int arr[n];
    printf("Enter The Elements");
    for(int i=0;i<n;i=i+1){
        scanf("%d",&arr[i]);
    }
    k=sizeof(arr)/sizeof(arr[0]);
    buildheap(arr,k);
    //In the Array in Max Heap Form
    printing(arr,k);
    //Array In Tree
    printf("\nIn The Tree Printing Inorder\n");
    maxheap* max=insertLevelOrder(arr,max,0,n);
    printInorder(max);


}