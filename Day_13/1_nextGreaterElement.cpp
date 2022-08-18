#include<bits/stdc++.h>
using namespace std;
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size());
        vector<int> ans;
        // stack me unko dalo jinka abhi NGE nikalana baki hai
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            // agar bda hai to nge set kr do fir usko pop krdo
            while(!st.empty()&&nums2[st.top()]<nums2[i]){
                nge[st.top()]=i;
                st.pop();
            }
            // agar bda nhi hai to push krdo baad me iska nge nikalo
            st.push(i);
        }
        // jo rah gye unka koi nhi tha to -1 krke pop krdo
        while(!st.empty()){
            nge[st.top()]=-1;
            st.pop();
        }
        for(int i=0;i<nums1.size();i++){
            auto itr = find(nums2.begin(),nums2.end(),nums1[i]);
            int temp = nge[itr-nums2.begin()]==-1?-1:nums2[nge[itr-nums2.begin()]];
            ans.push_back(temp);
        }
        return ans;
    }

vector<int> nextGreaterElement2(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
int main(){
    
}