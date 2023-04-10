#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int findBestMeetingPoint(vector<vector<int>> &mat)
{
     int n = mat.size(), m = mat[0].size();
     vector<int> row,col;

     // finding rowwise x cord
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++) if(mat[i][j]) row.push_back(i);
     }

     // finding colwise y cord
     for(int j=0;j<m;j++){
          for(int i=0;i<n;i++) if(mat[i][j]) col.push_back(j);
     }

     // mid point
     int x = row[row.size()/2];
     int y = col[col.size()/2];

     int dis = 0;
     for(auto &p : row) dis += abs(p-x);
     for(auto &p : col) dis += abs(p-y);

     return dis;
}

