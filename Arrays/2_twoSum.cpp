/*********************************************************************************************

Question :


Notes :
The basic idea is to maintain a hash table for each element num in nums, using num as key and its index (0-based) as value. For each num, search for target - num in the hash table. If it is found and is not the same element as num, then we are done.

The code is as follows. Note that each time before we add num to mp, we search for target - num first and so we will not hit the same element.
**********************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};
vector<int> twoSum(vector<int>& nums, int target){ // wrong approach
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]=i;
    }
    sort(nums.begin(),nums.end());
    int i=0;
    int j= nums.size()-1;
    while(i<j){
        if(nums[i]+nums[j]==target){
            ans.push_back(mp[nums[i]]);
            ans.push_back(mp[nums[j]]);
            break;
        }else if(nums[i]+nums[j]>target){
            j--;
        }else i++;
    }
    return ans;
}
vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> ans;
        for(int i=0; i<nums.size();i++){
            for(int j=i+1;j< nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
int main(){
    int target =9;
    vector <int> nums={2,7,11,15};
    cout<<"ans is : "<<twoSum(nums,target)[0]<<" "<<twoSum(nums,target)[1] <<endl;

}