#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O(N)
	Space Complexity: O(N)
*/


class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> freq;
        freq[arr[0]]++;
        int cnt =0;
        for(int i=1;i<n;i++){
            if(freq.find(k-arr[i])!=freq.end()) cnt+= freq[k-arr[i]];
            freq[arr[i]]++;
        }
        return cnt;
    }
};