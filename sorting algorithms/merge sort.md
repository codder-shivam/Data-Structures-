MERGE SORT ALGORITHM

Merge Sort is a Divide and Conquer algorithm.
It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
The mergeSort() function is used for merging two halves. 
The merge(arr, left, right, mid) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and
merges the two sorted sub-arrays into one. See following C++ implementation for details.

divide(arr[], left,  right)
If right > left
     1. Find the middle point to divide the array into two halves:  
             middle mid = (left+right)/2
     2. Call mergeSort for first half:   
             Call divide(arr, left, mid)
     3. Call divide for second half:
             Call divide(arr, mid+1, right)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, left, right, mid)
else    If left>=right             
             return; //brings out of the control of the current funcion thus,
             returning control to the previous called function.
