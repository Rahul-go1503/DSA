/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    //Math
    int maximumProduct(vector<int>& nums) {
        int n= nums.size();
        int l1,l2,l3,m1,m2;
        l1=l2=l3=INT_MIN;m1=m2=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>=l1){
                l3=l2;l2=l1;
                l1= nums[i];
            }
            else if(nums[i]>=l2){
                l3=l2;
                l2 = nums[i];
            }
            else if(nums[i]>=l3) l3= nums[i];
            if(nums[i]<=m1){
                m2=m1;
                m1= nums[i];
            }
            else if(nums[i]<=m2) m2 = nums[i];
        }
        return max(l1*l2*l3,l1*m1*m2);
    }
};