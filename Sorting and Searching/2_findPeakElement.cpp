/*********************************************************************************************

Question :


Notes :
Quick explanation here: the binary search always ensures that for both boundaries, they already ensure the out-of-boundary side smaller than them (take a look at the boundary update) , thus ensuring that it will end up at a local peak eventually.
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> nums) {
    int s= 0;
    int e= nums.size()-1;
    while(s<e){
        int mid = s + (e-s)/2;
        if((mid-1<0&&nums[mid]>nums[mid+1])||(mid+1>nums.size()-1&&nums[mid]>nums[mid-1])){
            cout<<"here "<<mid<<endl;
            return mid;
        }
        if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
            return mid;
        }
        if(nums[mid]>nums[mid+1]){
            e= mid;
        }else{
            s= mid+1;
        }

    }        
}
int findPeakElement(vector<int> nums) {
    int s= 0;
    int e= nums.size()-1;
    while(s<e){
        int mid = s + (e-s)/2;
        if(nums[mid]>nums[mid+1]){
            e= mid;
        }else{
            s= mid+1;
        }

    }
    return s;      
}

int main()
{
    cout<<findPeakElement({4,3,2,1})<<endl;
}