//The QuickSort Algorithm

#include<stdio.h>
#include<stdlib.h>

int swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
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

void quicksort(int arr[],int low, int high)
{
    if(low<high){
        int p=partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

int main()
{
    int n,*arr;
    
    printf("Enter the Number of Elements ");
    scanf("%d",&n);

    arr=(int*)malloc(sizeof(int)*n);
    printf("Entehr the Elements of the List");
    for(int i=0;i<n;i=i+1){
        scanf("%d",&arr[i]);
    }


    printf("\nThe Entered Elements Are\n");
    for(int i=0;i<n;i=i+1){
        printf("%d ",arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\nThe Sorted List Is\n");
    for(int i=0;i<n;i=i+1){
        printf("%d ",arr[i]);
    }

return 0;
}