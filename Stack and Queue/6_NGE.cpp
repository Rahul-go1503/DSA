#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(n), SC - O(n)


class Solution {
public:
    // For every num in nums, there is at most one push AND one pop operation. So it's O(N)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> s;
        unordered_map<int,int> m; // use un_map ,and via values bcoz we no need for every elem
        s.push(nums2[0]);
        for(int i=1;i<n;i++){
            // value at i is greater than values in stack
            while(!s.empty() && nums2[i]>s.top()){
                m[s.top()]=nums2[i];
                s.pop();
            }
            // push value at i
            s.push(nums2[i]);
        }
        
        vector<int> ans(nums1.size(),-1); // already assign -1 --> rem values in stack
        for(int i =0;i<nums1.size();i++){
            if(m.count(nums1[i])) ans[i] = m[nums1[i]];
        }
        return ans;
    }
};


// NSE via index for whole array;
// at ith index we check for how many elem it can be nge so we have to track for indexes.
vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && nums[i]<nums[s.top()]){
            ans[s.top()]=nums[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

//  via only values,, calulate for ith index
vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    vector<int> ans(n);
    stack<int> s; 
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        while(nums[i]>=s.top()){
            s.pop();
        }
        int curr = nums[i];
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}



// for circular NGE - 2
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n,-1);
        stack<int> idx;
        for(int i = 0;i<n || idx.size()>1; i++){
            if(i>2*n) break;
            while(idx.size() && nums[i%n]>nums[idx.top()]){
                nge[idx.top()] = nums[i%n];
                idx.pop();
            }
            if(i<n) idx.push(i);
        }
        return nge;
    }
};