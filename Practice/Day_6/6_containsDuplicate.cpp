#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate2(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        // for(int i=0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        return nums.size()-s.size();
}
bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]==2) return 1;
        }
        return 0;
}

int main(){
    vector<int> nums ={0};
    cout<<containsDuplicate2(nums)<<endl;
}