#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :
- subarray sum ---> Prefix sum
- tarsum = prefix[j] - prefix[i];
- tar == 0 => p[j]==p[i]; 
**********************************************************************************************/
/*
	Time Complexity: O(N)
	Space Complexity: O(N)
*/

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> s;
        int sum =0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) return true;
            sum+=arr[i];
            if(sum==0 || s.find(sum)!=s.end()) return true;
            s.insert(sum);
        }
        return false;
    }
};