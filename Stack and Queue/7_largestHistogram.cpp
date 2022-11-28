#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(n), SC - O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int>nse(n,n) , pse(n,-1); // indexes
        // create two monotonics stack
        stack<int> st,temp;
        
        // for nse
        for(int i = 0;i<n;i++){
            while(!st.empty() && h[i]<h[st.top()]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        st.swap(temp);
        
        // for pse
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && h[i]<h[st.top()]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx ,(nse[i]-pse[i]-1)*h[i]);
        }
        return mx;
    }
};