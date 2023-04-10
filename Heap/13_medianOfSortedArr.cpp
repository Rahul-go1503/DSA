#include<bits/stdc++.h>
using namespace std;
// wrong
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<int> mx;
        priority_queue<int,vector<int>,greater<int>> mn;
        for(int i=0;i<n;i++){
            if(mx.size()==0) mx.push(nums1[i]);
            // else if(mn.size()==0) mn.push(nums1[i]);

            if(mx.size() > mn.size()){
                int e = mx.top();
                if(nums1[i]<e){
                    mx.pop();
                    mx.push(nums1[i]);
                    mn.push(e);
                }
                else if(nums1[i] >= e) mn.push(nums1[i]);
            }
            else mx.push(nums1[i]);
        }
        for(int i=0;i<m;i++){
            if(mx.size()==0) mx.push(nums2[i]);
            // else if(mn.size()==0) mn.push(nums2[i]);

            if(mx.size() > mn.size()){
                int e = mx.top();
                if(nums2[i]<e){
                    mx.pop();
                    mx.push(nums2[i]);
                    mn.push(e);
                }
                else if(nums2[i] >= e) mn.push(nums2[i]);
            }
            else mx.push(nums2[i]);
        }

        double res;
        if((n+m)%2) return mx.top()*1.0;
        else return (mn.top() + mx.top())/2.0;
    }
};