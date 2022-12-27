#include <bits/stdc++.h>
using namespace std;

/*
 - Monotonic stack
 - vector is used as stack
 - O(N),O(k) - we are processing 1 elem at most 2 times, at most k elem in the stack
*/
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> sub;
        int cnt = 0, n = nums.size();
        for(int i=0;i<n;i++){
            while(sub.size() && (n-i)>k-cnt && sub.back()>nums[i]){
                sub.pop_back();
                cnt--;
            }
            if(cnt<k){
                sub.push_back(nums[i]);
                cnt++;
            }
        }
        return sub;
    }
};