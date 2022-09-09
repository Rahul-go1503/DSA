/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Array Kadane's Algorithm
    // Kadane’s Algorithm can be viewed both as greedy and DP
    int maxSubArray(vector<int>& arr) {
        int mx = INT_MIN,sum =0,n=arr.size();
        for(int i=0;i<n;i++){
            sum+= arr[i];
            mx = max(mx,sum);
            if(sum<0) sum=0;
        }
        return mx;
    }
};