#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i=0;i<32;i++){
            int set = 0;
            for(int j=0;j<n;j++){
                if(nums[j] & 1) set++;
                nums[j] >>= 1; // modifying nums[j] -> not recommended
            }
            res += set*(n-set);
        }

        return res;
    }
};

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size(), ans=0;
        for(int i=0;i<32;i++){
            int count=0; //Count of the no.of elements that have the 'i'th bit set
            for(int k=0;k<n;k++){
                count += (nums[k]>>i)&1; // not modifying nums[k]
            }
            ans += count*(n-count);
        }
        return ans;
    }
};