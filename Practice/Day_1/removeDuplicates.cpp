#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// pair <int,int> p;
// not able to solve
// Solution
int removeDuplicates2(vector<int>& nums) {
        int i=0;
        for (int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                nums[++i]=nums[j];
            }
        }
        return i+1;
}
  
int main(){
    vector<int> nums ={0,0,1,1,1,2,2,3,3,4};
    int ans=removeDuplicates2(nums);
    cout<<"ans is : "<<ans<<endl;
}