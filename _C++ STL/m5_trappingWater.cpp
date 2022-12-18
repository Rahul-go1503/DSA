#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Notes :

**********************************************************************************************/
/*
	Time Complexity: O(n)
	Space Complexity: O(n)
*/

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int i=0;
        long long ans=0;
        int * left = new int[n];
        int* right = new int[n];
        left[0]=-1; right[n-1]=-1;
        for(int i=1;i<n;i++){
            // can optimize left[i] only depends on left[i-1];
            left[i] = max(left[i-1],arr[i-1]);
            right[n-i-1] = max(right[n-i],arr[n-i]);
        }
        
        for(int i=1;i<n-1;i++){
            if(arr[i]<left[i] && arr[i]<right[i]){
                ans+=min(left[i],right[i])-arr[i];
            }
        }
        delete[] left;
        delete[] right;
        return ans;
    }
};
class Solution{
    //credits to manishanuwal2000
    
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        long long l = 0;
        long long r = n - 1;
        
        long long res = 0;
        long long mL = 0 , mR = 0; // longest left and right bars
        
        while(l <= r){
            // jab right me curr block height se jyada height ka block ho
            if(arr[l] <= arr[r]){
                // agar ml se bda hai to ml ko update kro
                if(arr[l] >= mL){
                    mL = arr[l];
                }
                // means water ml or arr[r] ke bich store ho skta hai
                else{
                    res += mL - arr[l];
                }
                l++;
            }
            // jab right wala left wale se chhota ho
            else {
                if(arr[r] >= mR){
                    mR = arr[r];
                }
                else {
                    res += mR - arr[r];
                }
                r--;
            }
        }
        
        return res;
    }
};