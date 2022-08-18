/*********************************************************************************************

Question : 474. Ones and Zeroes


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<string>& strs,int i, int m, int n){
        int arr[2]={0,0};
        for(int k=0;k<strs[i].length();k++){
            int ch = strs[i][k]-'0';
            arr[ch]++;
        }
        return max(solve(strs,i+1,m-arr[0],n-arr[1]),solve(strs,i+1,m,n));
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
    }
};