/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O(N)
	Space Complexity: O(N)

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    //backtracking
    void solve(string &digits, string map[], int i, int n,vector<string> &ans ,string letter){
        if(i==n){
            ans.push_back(letter);
            return;
        }
        
        for(int k = 0; k<map[digits[i]-'0'].length();k++){
            // cout<<map[digits[i]-'0'][k]<<endl;
            solve(digits,map,i+1,n,ans,letter+map[digits[i]-'0'][k]);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string letter;
        string map[10] = {"", "", "abc","def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        solve(digits,map,0,digits.length(),ans,letter);
        return ans;
    }
};