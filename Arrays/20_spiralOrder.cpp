#include <bits/stdc++.h>
using namespace std;
class Solution {
    //Array -- not solved
void solve(vector<vector<int>> &m,vector<int>&ans,int rs,int re,int cs,int ce){
    if(rs>re || cs>ce) return;
    for(int i=cs;i<=ce;i++){
        ans.push_back(m[rs][i]);
    }
    rs++;
    // if(++rs>re) return;
    for(int i=rs;i<=re;i++){
        ans.push_back(m[i][ce]);
    }
    ce--;
    if(re<rs) return;
    for(int i= ce;i>=cs;i--){
        ans.push_back(m[re][i]);
    }
    re--;
    if(ce<cs) return;
    for(int i=re;i>=rs;i--){
        ans.push_back(m[i][cs]);
    }
    cs++;
    // if(++cs>ce) return;
    solve(m,ans,rs,re,cs,ce);
    return;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs=0;
        int re=matrix.size()-1;
        int cs=0;
        int ce=matrix[0].size()-1;
        vector<int> ans;
        solve(matrix,ans,rs,re,cs,ce);
        return ans;
    }
};