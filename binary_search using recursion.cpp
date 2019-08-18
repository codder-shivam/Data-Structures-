#include<iostream>
using namespace std;

int bin_search(int arr[], int low, int high, int x)
{
    int mid=(low+high)/2;
    if(low>high) return -10;
    if(arr[mid]==x) return mid;
    if(arr[mid]<x)
         return bin_search(arr,mid+1,high,x);
    else
        return bin_search(arr,low,mid-1,x);
}
int main()
{
    int arr[10], range,low, high,x,pos;
    cout<<"\n enter the range of array :";
    cin>>range;
    cout<<"enter elements of array\n :";
    for(int i=0; i <range; i++)
    {
        cin>>arr[i];
    }
    cout<<"enter elment to be searched:";
    cin>>x;
    pos = bin_search(arr,0,range-1,x);
    cout<<pos+1;
    return 0;

}
