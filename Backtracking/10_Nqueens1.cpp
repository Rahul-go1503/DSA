#include <bits/stdc++.h>
using namespace std;

#define vvs vector<vector<string>>
#define vs vector<string>
#define vi vector<int>
class Solution {
    void dfs(int r, int n, vi &col, vi &dia1, vi &dia2, vs &board, vvs &res){
        if(r==n){
            res.push_back(board);
            return;
        }

        for(int c=0;c<n;c++){
            if(col[c] || dia1[r+c] || dia2[n-1+c-r]) continue;
            col[c] = dia1[r+c] = dia2[n-1+c-r] = 1;
            board[r][c] = 'Q';
            dfs(r+1,n,col,dia1,dia2,board,res);
            col[c] = dia1[r+c] = dia2[n-1+c-r] = 0;
            board[r][c] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vvs res;
        vs board(n,string(n,'.'));
        vi col(n), dia1(2*n+1), dia2(2*n+1);
        dfs(0,n,col,dia1,dia2,board,res);
        return res;
    }
};

// gfg
#define vvi vector<vector<int>>
#define vi vector<int>
class Solution{
    void dfs(int c, int n, vi &row, vi &dia1, vi &dia2, vi &board, vvi &res){
        if(c==n){
            res.push_back(board);
            return;
        }

        for(int r=0;r<n;r++){
            if(row[r] || dia1[r+c] || dia2[n-1+c-r]) continue;
            row[r] = dia1[r+c] = dia2[n-1+c-r] = 1;
            board[c] = r+1;
            dfs(c+1,n,row,dia1,dia2,board,res);
            row[r] = dia1[r+c] = dia2[n-1+c-r] = 0;
            board[c] = 0;
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        vvi res;
        vi board(n);
        vi row(n), dia1(2*n+1), dia2(2*n+1);
        dfs(0,n,row,dia1,dia2,board,res);
        return res;
    }
};