#include<iostream>
using namespace std;

void bubbleSort(int arr[] , int);

int main()
{
cout<<"\n Enter number of input elements: ";
int size;
cin>>size;
cout<<"\n Enter elements of array: ";
int arr[size];
for(int i=0;i<size;i++)cin>>arr[i];

bubbleSort(arr,size);

for(int i=0;i<size;i++)
cout<<arr[i]<<" ";
cout<<endl;

return 0;
}

void bubbleSort(int arr[] , int n)
{
int i=1,flag=1,j,temp;
while(i<n && flag){
flag = 0;

for(j=0;j< n-i;j++){
if(arr[j]>arr[j+1])
{
flag=1;
temp=arr[j+1];
arr[j+1]=arr[j];
arr[j]=temp;
}
}
i++;
}
}
