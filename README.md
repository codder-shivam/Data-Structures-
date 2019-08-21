# Data-Structures-
contains implementation of various data structures in optimized manner.



#RECURSIONS

recursion is a process of calling a fuction inside it's own function body.
In function declaration, function calls itself in an iterative manner until any particular condition
get satisfied.
Here, this condition is chcked in each function call(in each iteration) thus making a recursive call
to same function again and again. 

//sample recursion code...

int function(int n){   //function definition which returns an integer value

  if(condition){
  
    do this;
    
    return ;         //  can return 0 for false values  and 1 for true value  or any integer value
    
  }
  
  return ;            // return some int value on failing the if condition
  
}



#BINARY SEARCH

When we think searching algorithms we think of binary search algorithm.Indeed, this is a very useful
algorihm to study and implement.
In binary search,we look for an element X in a sorted array by first comparing to the midpoint of 
array. If X ia less than the midpoint,then we search the left half of the array. If X is greater than the
midpoint, then we search the right half of the array.
We than repeat this process, treating the right and left halves as subarrays Again we compare X to the 
midpoint of this subarray and then search wether it's left or right side. 

We repeat this process until we find the X or the subarray has size ZERO.
