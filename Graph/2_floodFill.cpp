/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<int>>& image,int initClr, int clr){
        if(i<0 || j<0 || i>=n || j>=m) return ;
        if(image[i][j]!=initClr) return;
        image[i][j]=clr;
        dfs(i+1,j,n,m,image,initClr,clr);
        dfs(i-1,j,n,m,image,initClr,clr);
        dfs(i,j+1,n,m,image,initClr,clr);
        dfs(i,j-1,n,m,image,initClr,clr);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initclr = image[sr][sc];
        if(initclr!=color){
            dfs(sr,sc,n,m,image,initclr,color);
        }
        return image;
    }
};