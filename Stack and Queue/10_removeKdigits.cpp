#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/
//"remove the first "peak" digit;"
// TC - O(N), SC - O(N+N)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length(),i;
        if(n==1 || n==k) return "0";
        stack<int> st;
        for(i=0;i<n;i++){
            while(st.size() && k && num[st.top()]>num[i]){
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(k--) st.pop();
        string ans;
        while(st.size()){
            ans.push_back(num[st.top()]);
            st.pop();
        }
        while(ans.size()>1 && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// TC - O(N), SC - O(N)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length(),i;
        if(n==1 || n==k) return "0";
        string res;
        for(i=0;i<n;i++){
            while(res.size() && k && res.back()>num[i]){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        while(k--) res.pop_back();
        while(res.size()>1 && res.front()=='0') res.erase(0,1);
        return res;
    }
};