/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int findPeakIndex(vector<int> &nums) {
    int s= 0;
    int e= nums.size()-1;
    while(s<e){
        int mid = s + (e-s)/2;
        if(nums[mid]>=nums[0]){
            s= mid+1;
        }else{
            e= mid;
        }

    }
    return s;      
}
int binarySearch(vector<int> & nums ,int s ,int e,int target){
    while(s<=e){
        int mid = s + (e-s)/2;
        cout<<"mid is "<<mid<<endl;
        if(target==nums[mid]){
            return mid;
        }
        if(target>nums[mid]){
            s=mid+1;
        }else{
            e= mid-1;
        }
    }
        return -1;
}
    int search(vector<int>& nums, int target) {
    int peakIndex = findPeakIndex(nums);
    cout<<"peak "<<peakIndex<<endl;
    int s,e;
    if(nums[peakIndex]<=target&&target<=nums[nums.size()-1]){
        s=peakIndex;
        e= nums.size()-1;
    }else {
        s=0;
        e=peakIndex-1;
    }
    return binarySearch(nums,s,e,target);
}


class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};
/*
For those who struggled to figure out why it is realmid=(mid+rot)%n: you can think of it this way:
If we want to find realmid for array [4,5,6,7,0,1,2], you can shift the part before the rotating point to the end of the array (after 2) so that the sorted array is "recovered" from the rotating point but only longer, like this: [4, 5, 6, 7, 0, 1, 2, 4, 5, 6, 7]. The real mid in this longer array is the middle point between the rotating point and the last element: (rot + (hi+rot)) / 2. (hi + rot) is the index of the last element. And of course, this result is larger than the real middle. So you just need to wrap around and get the remainder: ((rot + (hi + rot)) / 2) % n. And this expression is effectively (rot + hi/2) % n, which is (rot+mid) % n.
Hope it helps!
*/
int main()
{
    vector<int> nums = {5,1,3};
    int target = 3;
    cout<<"ans is "<<search(nums,target);
}