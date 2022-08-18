#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int k=n/2+1;
        int ans=nums[0];
        for(int i=0;i<n&&i+k-1<n;i++){
            if(nums[i]==nums[i+k-1]){
                ans=nums[i];
            }
        }
        return ans;
    }

    /******************not understand
    int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
    ********************************/
};