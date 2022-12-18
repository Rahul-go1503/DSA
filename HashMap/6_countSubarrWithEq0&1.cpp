#include <bits/stdc++.h>
using namespace std;

/*
- here we are just finding no of subarray with sum equal to zero => p[i]==p[j];
- if ask anything like equal no of 2 and 3 or -9 and -7 we will do the same, bcoz basic idea is to maintain balance
- intution - ??
*/
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        unordered_map<int,int> sumCnt;
        //better if we call curr_sum counter (moore algo ? )
        int curr_sum = 0;
        sumCnt[curr_sum]++; // jab first time 0 milega tab ke liye
        long long cnt = 0;
        for(int i =0;i<n;i++){
            if(arr[i]) curr_sum++;
            else curr_sum--;
            cnt += sumCnt[curr_sum]++; // initialization and increment simultaneously
        }
        return cnt;
    }
};