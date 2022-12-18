#include <bits/stdc++.h>
using namespace std;
/*
Merge two sorted array
start from back
size of nums1 = m+n; given 
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int> ans;
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i++]);
            }else{
                ans.push_back(nums2[j++]);
                
            }
        }
        if(!nums2.empty()){
            for(int k=j;k<n;k++){
                ans.push_back(nums2[k]);
            }
        }
        if(!nums1.empty()){
            for(int k=i;k<m;k++){
                ans.push_back(nums1[k]);
            }
        }
        nums1=ans;
        
    }
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int i = m - 1, j = n - 1, k = m + n - 1;
     while(i >= 0 and j >= 0) {
         if(nums1[i] < nums2[j]) {
             nums1[k--] = nums2[j--];
         } else {
             nums1[k--] = nums1[i--];
         }
     }
     while(j >= 0) {
         nums1[k--] = nums2[j--];
     }
 }
};