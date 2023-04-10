#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size(), res = 0, j = 0, k = -1;
        for(int i =0 ;i<n;i++){
            if(nums[i]>=left && nums[i]<=right){
                k = i;
            }
            if(nums[i]>right) j = i + 1, k = i;
            res += k - j + 1;
        }
        return res;
    }
};


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result=0, left=-1, right=-1;
        for (int i=0; i<A.size(); i++) {
            if (A[i]>R) left=i;
            if (A[i]>=L) right=i;
            result+=right-left;
        }
        return result;
    }
};