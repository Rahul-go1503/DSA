#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given 
number S and return the left and right index(1-based indexing) of that subarray.
*/
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long sum = 0;
        int i = 0 , si =0; 
        while(i<n){
            // if(s==0 && arr[i]==0) return {i+1,i+1};
            sum += arr[i++];
            while(si<i-1 && sum>s){
                sum -= arr[si++];
            }
            if(sum == s) return {si+1,i};
        }
        return {-1};
    }
};