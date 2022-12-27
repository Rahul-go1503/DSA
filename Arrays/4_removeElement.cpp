#include <bits/stdc++.h>
using namespace std;

//O(N),O(1)
class Solution {
public:
int removeElement(vector<int>& nums, int val) {
    int i=0;
    int ans=0;
    int j= nums.size()-1;
    if(j==-1) return ans;
    while (i<=j)
    {
        while(i <nums.size() && nums[i]!=val){i++;ans++;}
        if(nums[j]!=val && j>=i){
            swap(nums[i++],nums[j--]);
            ans++;
        }else j--;

    }
    return ans;
}
int removeElement2(int A[], int n, int elem) {
    int begin=0;
    for(int i=0;i<n;i++) if(A[i]!=elem) A[begin++]=A[i];
    return begin;
}
};

int removeElement(vector<int> &nums, int val) {
    int i = 0;
    int n = nums.size();
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
}