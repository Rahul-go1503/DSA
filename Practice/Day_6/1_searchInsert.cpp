#include <bits/stdc++.h>
using namespace std;
class Solution {
    int binarySearch(vector<int>& nums,int s,int e,int t){
        if(s>e) return s;
        int mid= (s+e)/2;
        if(nums[mid]==t) return mid;
        if(nums[mid]>t) return binarySearch(nums,s,mid-1,t);
        else return binarySearch(nums,mid+1,e,t);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
    int searchInsert2(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};