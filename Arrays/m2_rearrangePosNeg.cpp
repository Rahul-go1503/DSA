#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

Notes :

**********************************************************************************************/
/*  Time Complexity: O(N2) -- TLE
	Space Complexity: O(1)     */

class Solution {
public:
    void rotateArr(vector<int> &arr , int l ,int r){
        int temp = arr[r];
        while(l<r){
            arr[r]=arr[r-1];
            r--;
        }
        arr[l]=temp;
    }
    vector<int> rearrangeArray(vector<int>& arr) {
        int n= arr.size();
        int outplace =  -1;
        for(int i=0;i<n;i++){
            if(outplace>=0){
                if((arr[outplace]>0 && arr[i]<0)||(arr[outplace]<0 && arr[i]>0)) {
                    rotateArr(arr,outplace,i);
                    if(i-outplace>=2) outplace+=2;
                    else outplace =-1;
                }
            }
            else if((arr[i]>0 && i%2!=0)||(arr[i]<0 && i%2==0)){
                outplace=i;
            }
        }
        return arr;
    }
};
/*  Time Complexity: O(N) 
	Space Complexity: O(N)     */
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int size= arr.size();
        int* pos = new int[size/2];
        int* neg = new int[size/2];
        int p=0,n=0;
        for(int i=0;i<size;i++){
            if(arr[i]>0) pos[p++]=arr[i];
            else neg[n++]=arr[i];
        }
        p=n=0;
        for(int i=0;i<size;i++){
            if(i%2==0) arr[i]=pos[p++];
            else arr[i] = neg[n++];
        }
        delete []pos;
        delete []neg;
        return arr;
    }
};
// O(N),O(N)
vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n,0);
        int indexpos = 0, indexneg=1;
        for(auto num: nums){
            if(num>0){
                ans[indexpos] = num;
                indexpos+=2;
            }
            if(num<0){
                ans[indexneg] = num;
                indexneg += 2;
            }
        }
        return ans;
        
}