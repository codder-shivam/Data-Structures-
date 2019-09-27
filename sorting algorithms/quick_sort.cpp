//sorting of elements using  Quick Sort algorithm

#include<iostream>
using namespace std;

int  partition(int arr[] , int , int);  //function to make partitions making pivots
void quickSort(int arr[] , int , int);  //driver function that calls partition and fllows quicksort algorithm

int main()
{
  
  cout<<"\n Enter number of input elements: ";
  int size;
  cin>>size;
  cout<<"\n Enter elements of array: ";
  int arr[size];
  for(int i=0;i<size;i++)
    cin>>arr[i];

  quickSort(arr,0,size-1); // FUNCTION CALLED FOR SORTING ELEMENTS

  for(int i=0;i<size;i++)
    cout<<arr[i]<<",";
  cout<<endl;
  return 0;

}
//definition of quicksort function
void quickSort(int arr[] , int l ,int r) //l=left limit of subarray and r=right limit of subarray
{
  if(l<r){
    int q = partition(arr,l,r);  //q= index of pivot element
    quickSort(arr,l,q-1);        //quicksort called for left subarray
    quickSort(arr,q+1,r);        //quicksort called for right subarray
  }
}

int partition(int arr[] , int l ,int r)
{
  if(l<r){
    int j=l,i=j-1;
    int set=r,temp;  // pivot point
    for(int x=j;x<r;x++)
    {
      if(arr[j]>arr[set]) 
        j++;
      else{
        i++;
        temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        j++;
      }//else block ends
      
    }//for loop ends
    i++;
    temp=arr[set];
``  arr[set]=arr[i];
``  arr[i]=temp;
``  return i;
  }//if block ends
}


