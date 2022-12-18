/*********************************************************************************************

Question :
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
Any answer with a calculation error less than 10-5 will be accepted.

Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx = 0;
        double sum = 0;
        int n = nums.size(); int i =0;

        // reach to window
        while(i<k) sum+= nums[i++];

        mx = sum;
        // slide window
        while(i<n){
            sum-= nums[i-k]-nums[i++];
            if(sum>mx) mx = sum;
        }
        return mx/k;
    }
};

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size() ,s = 0, i=0;
        int sum = 0;
        while(i<k) sum += nums[i++];
        double avg = sum*1.0/k;
        for(;i<n;i++){
            sum += nums[i] - nums[s++];
            avg= max(avg,sum*1.0/k);
        }
        return avg;
    }
};