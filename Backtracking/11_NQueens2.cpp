#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
class Solution {
    void dfs(int &cnt, int r, int n,vi &col, vi &dia1, vi &dia2){
        if(r==n){
            cnt++;
            return;
        }
        for(int c=0;c<n;c++){
            if(col[c] || dia1[r+c] || dia2[n+c-r]) continue;
            col[c] = dia1[r+c] = dia2[n+c-r] = 1;
            dfs(cnt,r+1,n,col,dia1,dia2); 
            col[c] = dia1[r+c] = dia2[n+c-r] = 0;
        }
    }
public:
    int totalNQueens(int n) {
        vi col(n), dia1(2*n+1), dia2(2*n+1);
        int cnt = 0;
        dfs(cnt,0,n,col,dia1,dia2);
        return cnt;
    }
};