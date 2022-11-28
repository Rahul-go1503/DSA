#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(N), SC - O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& push, vector<int>& pop) {
        int n1 = push.size();
        int n2 = pop.size();
        int i = 0, j = 0;
        stack<int> st;
        while(i<=n1){
            while(st.size() && st.top()==pop[j]){
                st.pop();
                j++;
            }
            if(i<n1) st.push(push[i++]);
            else i++;
        }
        return j==n2;
    }
};