#include<bits/stdc++.h>
using namespace std; 
bool solve(int move,int i,int j,vector<vector<int>> &res){
    res[i][j] = move;
    int n = res.size(), m = res[0].size();
    if(move==n*m-1) return 1;
    int dx[] = {-2,-1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int d=0;d<8;d++){
        int x = i + dx[d];
        int y = j + dy[d];
        if(x<0 || y<0 || x>=n || y>=m || res[x][y] !=-1) continue;
        if(solve(move+1,x,y,res)) return 1;
    }
    res[i][j] = -1;
    return 0;
}
vector<vector<int>> knightTour(int n, int m) {
    /* 
        Return matrix of size n*m where integer
        at cell(i, j) represent move number of knight to reach that
        cell. Move number start from 0.

        It may be possible that there is no possible order to visit each cell
        exactly once. In that case, return a matrix of size n*m having all the values
        equal to -1.
    */

    vector<vector<int>> res(n,vector<int>(m,-1));
    bool fl = false;
    if(solve(0,0,0,res)) return res;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(solve(0,i,j,res)) {fl = true; break;}
    //     }
    //     if(fl) break;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<< res[i][j] << " ";
    //     }
    //     cout<<endl;
    // }
    return res;
}