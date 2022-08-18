/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

pair<int,int> ceilingAndFloor(vector<int>&nums,int x){
    int s=0;
    int e=nums.size()-1;
    pair<int,int> ans= make_pair(-1,-1);
    while(s<=e){
        int mid = s + (e-s)/2;
        if(nums[mid]==x){
            ans = make_pair(x,x);
            return ans;
        }
        else if(nums[mid]>x){
            ans.second=nums[mid];
            e=mid-1;
        }else{
            ans.first=nums[mid];
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = { 1, 2, 8, 10, 10, 12, 19 };
    int x = -18;
    pair<int,int> ans = ceilingAndFloor(arr, x);
    cout << "ceiling of " << x << " is " << ans.first<<" "<<ans.second<<endl;
 
    return 0;
}