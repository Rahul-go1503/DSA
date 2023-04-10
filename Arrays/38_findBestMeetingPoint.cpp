#include <bits/stdc++.h> 
using namespace std;
int findBestMeetingPoint(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int init_dis = 0;

    int left[n] ={}, top[m] = {};
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mat[i][j]==1){
                init_dis += i + j;
                left[i]++, top[j]++;
            }

        }
    }
    int right[n+1] = {};
    for(int i=n-1;i>=0;i--){
        right[i] += right[i+1] + left[i];
        // if(i==0) left[0] = 0;
        // else left[i] = left[i-1];
    }
    int bottom[m+1] = {};
    for(int j=m-1;j>=0;j--){
        bottom[j] = bottom[j+1] + top[j];
        // if(j==0) top[0] = 0;
        // else top[j] = top[j-1];
    }
    for(int i=1;i<n;i++) left[i] += left[i-1];
    for(int i=n-1;i>0;i--) left[i] = left[i-1];

    for(int i=1;i<m;i++) top[i] += top[i-1];
    for(int i=m-1;i>0;i--) top[i] = top[i-1];
    left[0] = right[0], top[0] = bottom[0];

    int mn = init_dis;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            int curr_dis = init_dis - right[i] + left[i] - bottom[j] + top[j];
            mn = min(mn,curr_dis);
        }
    }
    return mn;
}

