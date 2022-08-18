#include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     set<int> s1(nums1.begin(),nums1.end());   
     set<int> s2(nums2.begin(),nums2.end());
     vector<int> ans;
     auto itr1 = s1.begin(); 
     auto itr2 = s2.begin(); 
     while(itr1!=s1.end()&&itr2!=s2.end()){
         if(*itr1==*itr2){
             ans.push_back(*itr1++);
             *itr2++;
         }else if(*itr1>*itr2) *itr2++;
         else *itr1++;
     }
     return ans;   
    }

vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto n : nums2) {
            if (s.erase(n)) {
                ans.push_back(n);
            }
        }
        return ans;
    }