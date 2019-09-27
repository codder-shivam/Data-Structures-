#include<iostream>
using namespace std;

int  partition(int arr[] , int , int);
void quickSort(int arr[] , int , int);

int main()
{
cout<<"\n Enter number of input elements: ";
int size;
cin>>size;
cout<<"\n Enter elements of array: ";
int arr[size];
for(int i=0;i<size;i++)cin>>arr[i];

quickSort(arr,0,size-1);

for(int i=0;i<size;i++)
cout<<arr[i]<<",";
cout<<endl;
return 0;

}

void quickSort(int arr[] , int l ,int r)
{

if(l<r){
int q = partition(arr,l,r);
quickSort(arr,l,q-1);
quickSort(arr,q+1,r);

}
}

int partition(int arr[] , int l ,int r)
{

if(l<r){
int j=l,i=j-1;
int set=r,temp;  // pivot point
for(int x=j;x<r;x++){
if(arr[j]>arr[set]) j++;
else{
i++;
temp=arr[j];
arr[j]=arr[i];
arr[i]=temp;
j++;
}
}
i++;
temp=arr[set];
arr[set]=arr[i];
arr[i]=temp;
return i;
}
}


