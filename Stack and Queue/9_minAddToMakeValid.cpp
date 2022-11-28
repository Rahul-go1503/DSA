#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(N), SC - O(1) 0ms and 100%
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int op = 0 ,res =0;
        for(auto &ch : s){
            if(ch=='(') op++;
            else if(op==0 && ch==')') res++;
            else op--;
        }
        return res+op;
    }
};