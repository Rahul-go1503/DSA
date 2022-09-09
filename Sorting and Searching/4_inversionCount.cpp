/*********************************************************************************************

Question :


Notes :
 a[i] is greater than a[j], then there are (mid – s +1 -i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
**********************************************************************************************/

/*
	Time Complexity: O(Nlog(N))
	Space Complexity: O(N) -->heap
*/


#include <bits/stdc++.h>
using namespace std;

// inhance merge sort -- 
class Solution{
  public:
    long long merge(long long arr[], long long s, long long m , long long e){
        long long *f = new long long[m-s+1];
        long long *sa = new long long[e-m];
        long long i=0, j=0,cnt=0,k=s;
        
        for(long long idx=s;idx<=m;idx++) f[i++] = arr[idx];
        for(long long idx=m+1;idx<=e;idx++) sa[j++] = arr[idx];
        
    	i=0; j=0;
        while(i<m-s+1 && j<e-m){
            if(f[i]<=sa[j]) arr[k++]=f[i++];
            else{
                 arr[k++] = sa[j++];
                 cnt+= m-s+1-i;
            }
        }
        while(i<m-s+1) arr[k++]= f[i++];
        while(j<e-m) arr[k++] = sa[j++];
    
        delete []f;
        delete[]sa;
        return cnt;
    }

    long long mergeSort(long long arr[], long long s, long long e){
        // at least 2 elem
        if(s>=e) return 0;
        long long cnt = 0;
        long long mid = (s+e)/2 ;
        cnt+= mergeSort(arr,s,mid);
        cnt+= mergeSort(arr,mid+1,e);
    
        return cnt + merge(arr,s,mid,e);
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }

};

int getInvCount(int arr[],int n)
{
    // Create an empty set and insert first element in it
    multiset<int> set1;
    set1.insert(arr[0]);
  
    int invcount = 0; // Initialize result
  
    multiset<int>::iterator itset1; // Iterator for the set
  
    // Traverse all elements starting from second
    for (int i=1; i<n; i++)
    {
        // Insert arr[i] in set (Note that set maintains
        // sorted order)
        set1.insert(arr[i]);
  
        // Set the iterator to first greater element than arr[i]
        // in set (Note that set stores arr[0],.., arr[i-1]
        itset1 = set1.upper_bound(arr[i]);
  
        // Get distance of first greater element from end
        // and this distance is count of greater elements
        // on left side of arr[i]
        invcount += distance(itset1, set1.end());
    }
  
    return invcount;
}
/*
Note that the worst case time complexity of above implementation is O(n2) as distance function in STL takes O(n) time worst case, but this implementation is much simpler than other implementations and would take much less time than Naive method on average.
*/