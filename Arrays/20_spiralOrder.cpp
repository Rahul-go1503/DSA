#include <bits/stdc++.h>
using namespace std;
class Solution {
    //Array --  solved
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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int top = 0, down = mat.size();
        int left = 0, right = mat[0].size();

        int d = 0,k=0;

        vector<int> res(down*right);
        down--,right--;
        while(top<=down && left<=right){
            if(d==0){
                for(int i = left;i<=right;i++) res[k++] = mat[top][i];
                top++;
            }
            else if(d==1){
                for(int i = top;i<=down;i++) res[k++] = mat[i][right];
                right--;
            }
            else if(d==2){
                for(int i = right;i>=left;i--) res[k++] = mat[down][i];
                down--;
            }else{
                for(int i = down;i>=top;i--) res[k++] = mat[i][left];
                left++;
            }

            d = (d+1)%4;
        }
        return res;
    }
};