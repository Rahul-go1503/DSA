#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them,
the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.
**********************************************************************************************/

// TC - O(), SC - O()
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int mx = arr[0];
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>mx) mx = arr[i];
            if(i==mx) cnt++;
        }
        return cnt;
    }
};