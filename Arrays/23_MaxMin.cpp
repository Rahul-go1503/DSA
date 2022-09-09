/*********************************************************************************************

Question :
Given an array A of size N of integers. Your task is to find the sum of minimum and maximum elements in the array.

Notes :

**********************************************************************************************/

/*
	Time Complexity: O(N)
	Space Complexity: O(1)
    compar. = 2N
	Where 'N' is the total number of elements in the array.

    Approach 2 
    Time Complexity: O(n)
    Auxiliary Space: O(1) as no extra space was needed.

    Total number of comparisons: Different for even and odd n, see below: 

       If n is odd:    3*(n-1)/2  
       If n is even:   1 Initial comparison for initializing min and max, 
                           and 3(n-2)/2 comparisons for rest of the elements  
                      =  1 + 3*(n-2)/2 = 3n/2 -2
*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int findSum(int arr[], int N)
    {
        
    	int mx = arr[0];
    	int mn = arr[0];
    	for(int i=1;i<N;i++){
    	    if(arr[i]>mx) mx = arr[i];
    	    else if(arr[i]<mn) mn = arr[i];
    	}
    	return mx+mn;
    }

};

struct Pair
{
    int min;
    int max;
};
 
struct Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;    
    int i;
     
    // If array has even number of elements
    // then initialize the first two elements
    // as minimum and maximum
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])    
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
         
        // Set the starting index for loop
        i = 2;
    }
     
    // If array has odd number of elements
    // then initialize the first element as
    // minimum and maximum
    else
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
         
        // Set the starting index for loop
        i = 1;
    }
     
    // In the while loop, pick elements in
    // pair and compare the pair with max
    // and min so far
    while (i < n - 1)
    {        
        if (arr[i] > arr[i + 1])        
        {
            if(arr[i] > minmax.max)    
                minmax.max = arr[i];
                 
            if(arr[i + 1] < minmax.min)        
                minmax.min = arr[i + 1];    
        }
        else       
        {
            if (arr[i + 1] > minmax.max)    
                minmax.max = arr[i + 1];
                 
            if (arr[i] < minmax.min)        
                minmax.min = arr[i];    
        }
         
        // Increment the index by 2 as
        // two elements are processed in loop
        i += 2;
    }        
    return minmax;
}