#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
        unordered_map<char,int> m = {{'[',-3},{'{',-2},{'(',-1},{')',1},{'}',2},{']',3}};
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]<0) st.push(s[i]);
           else{
               if(st.empty()) return 0;
               if(m[st.top()]+m[s[i]]!=0) return 0;
               st.pop();
           }
        };
        if(st.empty()) return true;
        else return false;
        
}
bool isValid2(string s) {
        string st;
        unordered_map<char,char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        st.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if(mp[st.back()] == s[i])
                st.pop_back();
            else
                st.push_back(s[i]);
        }
        return st.size() ? 0 : 1;
    }
int main(){
    string s="}";
    cout<<" ans is "<<isValid2(s)<<endl;
}