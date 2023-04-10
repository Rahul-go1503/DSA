#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int mn1, mn2,idx;
void calMin(int x,int i){
   if(x<mn1){
      mn2 = mn1;
      mn1 = x;
      idx = i;
   }
   else if(x<mn2){
      mn2 = x;
   }
}
int paintCost(int n, int k, vector<vector<int>> &costs)
{
   int prev1 = 0, prev2 = 0, index = -1;
   for(int i=0;i<n;i++){
      mn1 = mn2 = INT_MAX;
      for(int j=0;j<k;j++){
         if(j != index) calMin(costs[i][j] + prev1, j);
         else calMin(costs[i][j] + prev2, j);
      }
      prev1 = mn1, prev2 = mn2, index = idx;
   }
   return prev1;
}