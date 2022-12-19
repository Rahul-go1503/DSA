#include <bits/stdc++.h>
using namespace std;

/*
Idea - We greedily process elements starting from the smallest value, WHY smallest value but not an arbitrary value?
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;

        int pairs = 0; // no need of this variable
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(mp[arr[i]] == 0 || arr[i]==0 && mp[arr[i]]<=1) continue;
            if(mp.find(2*arr[i]) != mp.end() && mp[2*arr[i]]>0){
                mp[arr[i]]--;
                mp[2*arr[i]]--;
                pairs++;
            } // else can return false here as we haven't find any match
        }
        return pairs == n/2;
    }
};