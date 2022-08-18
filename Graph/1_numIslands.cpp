/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=n || j>=m) return ;
        if(grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(i+1,j,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<"i "<<i<<" j "<<j<<" grid[i][j] "<<grid[i][j]<<endl;
                if(grid[i][j]=='1'){
                    dfs(i,j,n,m,grid);
                    cout<<"enter here"<<endl;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main(){
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    Solution s;
    cout<<"ans is "<<s.numIslands(grid)<<endl;

}