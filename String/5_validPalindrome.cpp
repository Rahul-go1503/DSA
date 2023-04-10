/*********************************************************************************************

Question :
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Notes :

**********************************************************************************************/
//3 times wrong :( first wrong intertep question and silly mistake j-- != j-1;
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int cnt=1;
    bool solve(string &s , int i, int j, char c){
            cout<<"cnt is "<<cnt++<<endl;
        while(i<j){
            // if(s[i]==c) i++;
            // if(s[j]==c) j--;
            cout<<"1st : s[i] : "<<s[i]<<" s[j] : "<<s[j]<<endl;
            if(s[i]!=s[j]){
                cout<<"s[i] : "<<s[i]<<" s[j] : "<<s[j]<<endl;
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n=s.length();
        int j=n-1;
        for(int i=0;i<j;i++){
            cout<<"Start: s[i] : "<<s[i]<<" s[j] : "<<s[j]<<endl;
            if(s[i]!=s[j]){
                // if(solve(s,i+1,j,s[i])) return true;
                // else return solve(s,i,j-1,s[i]);
                return solve(s,i+1,j,s[i])||solve(s,i,j-1,s[j]);
            }
            j--;

        }
        cout<<"from final line :"<<endl;
        return true;
    }
};
int main(){
    Solution s;
    cout<<"ans is : "<<s.validPalindrome("cbbcc")<<endl;
}

// resubmit
class Solution {
    bool check(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return check(s,i+1,j) || check(s,i,j-1);
            i++,j--;
        }
        return true;
    }
};