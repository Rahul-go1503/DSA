/********************************************************************************************* 
 
Question : 


**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        int n1 = s.length();
        int n2 = t.length();
        int i=0;
        while(n1>i){
            if(s[i]=='#'&& st1.empty()){
                i++;
                continue;
            }
            else if(s[i]=='#'&& !st1.empty()){
                st1.pop();
                i++;
            }else{
                st1.push(s[i++]);
            }
        }
        int j=0;
        while(n2>j){
            if(t[j]=='#'&& st2.empty()){
                j++;
                continue;
            }
            else if(t[j]=='#'&& !st2.empty()){
                st1.pop();
                j++;
            }else{
                st1.push(t[j++]);
            }
        }
        while(!st1.empty() && !st2.empty()){
            if(st1.top()!=st2.top()) return false;
            st1.pop();
            st2.pop();
        }
        if(st1.empty()&&st2.empty()) return true;
        return false;
    }

 bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1, back;
        while (i >=0 || j>=0) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<backspaceCompare(s1,s2)<<endl;
}