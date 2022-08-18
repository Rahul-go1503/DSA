#include<bits/stdc++.h>
using namespace std;
// easy
// NATS ~ DP, divide and conquer
int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxSum= pow(10,-4);
    cout<<typeid(maxSum).name()<<" "<< maxSum<<endl;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        maxSum=max(maxSum,sum);
    }
    return maxSum;


        
    }
int main(){
    vector <int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<"ans is : "<<maxSubArray(nums)<<endl;

}