#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n = nums.size();
        if(f<s) swap(f,s);
        vector<int> pre(n+1,0);
        // pre[0] = nums[0];
        for(int i=1;i<=n;i++) pre[i] = nums[i-1] + pre[i-1];

        int mx = -1;
        // brute force
        // basically checking for all possible soln
        for(int i = f-1;i<n;i++){
            int sum = pre[i+1] - pre[i+1-f],sum2=0;
            for(int j = s-1;j<n;j++){
                if(j<i && j+f>i) j=i+s-1;
                else{
                    sum2 = max(sum2,pre[j+1] - pre[j+1-s]);
                }
            }
            sum += sum2;
            mx = max(mx,sum);
        }
        return mx;
    }
};