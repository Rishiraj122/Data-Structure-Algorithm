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
    int n,k,*arr,Diamonds=0,testcase=0;
    scanf("%d",&testcase);
    
    while(testcase>0){

        scanf("%d%d",&n,&k);
        arr=(int*)malloc(sizeof(int)*n);
    
        for(int i=0;i<n;i=i+1){
            scanf("%d",&arr[i]);
        }


        for(int j=0;j<k;j=j+1){
            quickSort(arr,0,n-1);
            Diamonds=Diamonds+arr[n-1];
            arr[n-1]=arr[n-1]/2;
        }

        printf("%d\n",Diamonds);
        Diamonds=0;
        testcase=testcase-1;
    }


    

return 0;
}