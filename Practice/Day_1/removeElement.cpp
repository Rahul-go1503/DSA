#include<iostream>
#include<vector>
using namespace std;
// int removeElement(vector<int>& nums, int val) {
//     int i=0;
//     int j= nums.size()-1;
//     if(j==-1) return 0;
//     while (i<j)
//     {
//         while(nums[i]!=val && i <nums.size()) i++;
//         if(nums[j]!=val && j>i){
//             swap(nums[i],nums[j]);
//             i++;j--;
//         }else j--;

//     }
//     // if(nums[i]!=val && i <nums.size()) return i+1;
//     if(i <nums.size()){
//         if(nums[i]!=val) return i+1;
//     }
//     else return i;       
// }

// Solution
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
int main(){
    vector<int> nums={3,3};
     int val=5;
     int ans=removeElement(nums,val);
     for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
     cout<<"ans is : "<<ans<<endl;
}