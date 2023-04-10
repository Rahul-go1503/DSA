#include <bits/stdc++.h>
using namespace std;

/*
 - lower and upper bound implementation.
*/


// logN , logN -> recursive calls in stack
class Solution {
    int findFirst(vector<int> &nums, int s, int e, int tar){
        if(s > e) return -1;
        if(s==e && nums[s]== tar) return s;
        else if(s ==e && nums[s] != tar) return -1;
        int mid = s + (e-s)/2;
        if(nums[mid] >= tar) return findFirst(nums,s,mid,tar);
        else return findFirst(nums,mid+1,e,tar);
    }

    int findLast(vector<int> &nums, int s, int e, int tar){
        if(s > e) return -1;
        if(s==e && nums[s]== tar) return s;
        else if(s==e && nums[s] != tar) return -1;
        int mid = s + (e-s)/2 + 1; // mid is next to mid
        if(nums[mid] > tar) return findLast(nums,s,mid-1,tar);
        else return findLast(nums,mid,e,tar);
    }
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int n = nums.size();
        int fidx = findFirst(nums,0,n-1,tar); 
        int lidx = findLast(nums,0,n-1,tar);
        return {fidx,lidx}; 
    }
};


// iterative
vector<int> searchRange(int A[], int n, int target) {
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;
    
    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;	// Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;				// So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}