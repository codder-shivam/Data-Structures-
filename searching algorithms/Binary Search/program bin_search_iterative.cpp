#include<stdio.h>
void quick_sort(int[],int,int);
int part(int[],int,int);
int main()
{
    int arr[50],n,i;
    printf("Enter elements to be sorted : ");
    scanf("%d",&n);
    printf("\nEnter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    printf("\nArray after sorting : ");
    for(i=0;i<n;i++)
        printf("%d",arr[i]);
    return 0;
}

void quick_sort(int arr[],int l,int u)
{
    int j;
    if(l<u){
        j=part(arr,l,u);
        quick_sort(arr,l,j-1);
        quick_sort(arr,j+1,u);
    }
}

int part(int arr[],int l, int u)
{
    int v,i,j,temp;
    v=arr[l];
    i=l;
    j=u+1;
    do{
        do
            i++;
        while(arr[i]<v&&i<=u);
        do
            j--;
        while(v<arr[j]);
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    arr[i]=arr[j];
    arr[j]=v;
    return (j);
}