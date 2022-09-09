/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O(mn)
	Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    void insert(long long arr2[],long long int elem, int idx){
        for(int i=0;i<idx-1;i++){
            arr2[i]=arr2[i+1];
        }
        arr2[idx-1] = elem;
    }
    void arrange(long long arr[],int m){
        for(int i=1;i<m;i++){
            if(arr[i-1]<arr[i]) break;
            swap(arr[i-1],arr[i]);
        }
    }
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            for(int i=0;i<n;i++){
                if(arr1[i]>arr2[0]){
                    swap(arr1[i],arr2[0]);
                    // int j = upper_bound(arr2,arr2+m,arr2[0])- arr2;
                    // insert(arr2,arr2[0],j);
                    arrange(arr2,m);
                }
            }
        } 
};

/*
	Time Complexity: O((m+n)log(m+n))
	Space Complexity: O(1)
*/
void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
   
    // Until i less than equal to k
    // or j is less than m
    while (i <= k && j < m) {
        if (arr1[i] < arr2[j])
            i++;
        else {
            swap(arr2[j++], arr1[k--]);
        }
    }
   
    // Sort first array
    sort(arr1, arr1 + n);
   
    // Sort second array
    sort(arr2, arr2 + m);
}


/*
    [Using Euclidean Division Lemma]
	Time Complexity: O(m+n)
	Space Complexity: O(1)
*/