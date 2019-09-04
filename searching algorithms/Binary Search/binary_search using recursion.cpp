//Write a program to implement BINARY SEARCH algorithm recursively.

#include<iostream>
using namespace std;

int bin_search(int arr[], int low, int high, int x)
{
if(high<=low)
{
int mid = low + (high-low)/2 ;

//if element is present at middle itself
if(arr[mid]==x) return mid;

//if element is smaller than mid and is in left subarray
if(arr[mid]>x)
   	return bin_search(arr,low,mid-1,x);

//else element is present in right subarray
   	return bin_search(arr,low,mid-1,x);
}
//when element is missing in array
return -1;
}
int main()
{
int arr[10], range,low, high,x;
cout<<"\n enter the range of array :";
cin>>range;
cout<<"enter elements of array\n :";
for(int i=0; i <range; i++)
{
   cin>>arr[i];
}
cout<<"enter elment to be searched:";
cin>>x;
int pos = bin_search(arr,0,range-1,x);
//DISPLAY OUTPUT

(pos==-1)? cout<<"\nElement is not present in array...": cout<<"/nElement is present at position "<<pos+1;

return 0;

}
