#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/missing-number/solutions/2082522/C++-or-5-Approaches-or-Daily-LeetCoding-Challenge-May-Day-28/
*/
/*
- Math - O(N),O(1);
*/
int missingNumber(vector<int>& nums) {
    int n= nums.size(),sum=0;
    int zeroToNSum=n*(n+1)/2;

    for(int i=0;i<n;i++) sum+=nums[i];
    return (zeroToNSum-sum);
}

int missingNumber2(vector<int>& nums) {
    long n = nums.size();
    return n * (n+1) / 2 - accumulate(begin(nums), end(nums), 0);
}
// Using long for Java and C++ to prevent overflow (the n*(n+1) 
// overflows ints already for n=46341, and then the /2 causes an actual wrong result).

/*
-Bit manupaltion - O(N),(1);
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i++;
        }

        return result;
    }
};
// Awesome solution! Perfectly avoid the integer overflow thing.

int missingNumber(vector<int>& nums) {
    
    int n = nums.size();
    int ans = n;
    
    for(int i = 0 ; i < n ; i++){
        while(nums[i] != n and nums[i] != i){
            swap(nums[i], nums[nums[i]]);
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        if(nums[i] != i){
            ans = i;
            break;
        }
    }
    
    return ans;
    
}