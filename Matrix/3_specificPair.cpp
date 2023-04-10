#include<bits/stdc++.h>
using namespace std;

int findMaxValue(vector<vector<int>>& mat, int n) {
	
    vector<vector<int>> mx(n,vector<int>(n,INT_MIN));
    int t1=INT_MIN,t2 = INT_MIN;
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            mx[i][j] = max(mx[i+1][j+1],mat[i+1][j+1]);
            if(i+2<n) t1 = max(mx[i+2][j+1],mat[i+2][j+1]);
            if(j+2<n) t2 = max(mat[i+1][j+2],mat[i+1][j+2]);
            int t = max(t1,t2);
            mx[i][j] = max(mx[i][j],t);
        }
    }

    int res = INT_MIN;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            res = max(res,mx[i][j]-mat[i][j]);
        }
    }
    return res;
}
