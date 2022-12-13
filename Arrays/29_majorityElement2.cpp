#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//Boyer–Moore majority vote algorithm
// O(N+N)
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // max can be only 2 elem
        int one = 0, two =0;
        
        // initialize with any value
        int n1 = 2, n2 = 3;
        for(auto &num : nums){
            if(num==n1) one++;
            else if(num==n2) two++;
            else if(one==0){
                n1 = num;
                one++;
            }
            else if(two==0){
                n2 = num;
                two++;
            }
            else{
                one--;
                two--;
            }
        }
        int cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==n1){
                cnt1++;
            }
            if(nums[i]==n2){
                cnt2++;
            }
        }
        vector<int> elem;
        if(cnt1>n/3) elem.push_back(n1);
        if(cnt2>n/3) elem.push_back(n2);
        return elem;
    }
};

class Solution {
public:
    // nlogn
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        vector<int> elem;
        while(i<n){
            if(i+n/3<n && nums[i]==nums[i+n/3]){
                elem.push_back(nums[i]);
                i+=n/3+1;
                while(i<n && nums[i]==nums[i-1]) i++;
            }else i++;
        }
        return elem;
    }
};