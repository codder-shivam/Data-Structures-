#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

void divide(int arr[],int ,int );
void mergeSort(int arr[],int ,int ,int);
int size;

int main()
{

	cout<<"\nEnter size of array: ";cin>>size;
	int arr[size];
	cout<<"\nEnter elements of array: \n";
	for(int i=0;i< size;i++)cin>>arr[i];

	cout<<"\n Unsorted array is : \n";
	for(int i=0;i<size;i++) cout<<arr[i]<<", ";
	cout<<endl;
    auto start=high_resolution_clock::now();
	divide(arr,0,size-1);
	auto stop=high_resolution_clock::now();

    cout<<"\n Final Sorted array is : \n";
	for(int i=0;i<size;i++)cout<<arr[i]<<", ";

	auto duration=duration_cast<microseconds>(stop-start);
	cout<<"Total time taken by merge sort in sorting is :"<<duration.count()<<"microseconds"<<endl;
	return 0;
}
void divide(int arr[],int left,int right)
{
    int mid=(left+right)/2;
    if(left>=right)return;
    divide(arr,left,mid);
    divide(arr,mid+1,right);
    mergeSort(arr,left,right,mid);
    return ;
}
void mergeSort(int arr[],int left,int right,int mid)
{

    int n=right-left+1;
    int temp[n];
    for(int i=0;i<n;i++)
        temp[i]=arr[i+left];

    cout<<"temp :";
	for(int x=0;x<n;x++){cout<<temp[x]<<", ";}cout<<endl;

	int i=0;
	int j=mid-left+1;
	int k=left;
	int m=j;
	while(i<m && j<n )
    {
        if(temp[i]<=temp[j])
        {
            arr[k]=temp[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=temp[j];
            j++;
            k++;
        }
    }
    while(i<m)
    {
        arr[k] = temp[i];
        i++;
        k++;
    }
    while(j<n)
    {
        arr[k]=temp[j];
        j++;
        k++;
    }

	cout<<"Updated subarray :";
	for(int x=left;x<k;x++){cout<<arr[x]<<", ";}cout<<endl;

	cout<<"updated array :"	;
	for(int x=0 ; x< size ; x++){cout<<arr[x]<<", ";}cout<<endl;
	return ;
}
