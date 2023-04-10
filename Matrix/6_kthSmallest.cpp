#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;

// same as merge k sorted array
int kthSmallest(int arr[MAX][MAX], int n, int k)
{
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    int res,cnt=0;

    for(int i=0; i<n;i++){
        pq.push({arr[i][0],i,0});
    }
    while(cnt<k){
        vector<int> v = pq.top();
        int val = v[0];
        int r = v[1];
        int c = v[2];
        pq.pop();
        res = val;
        cnt++;
        if(c + 1 < n) pq.push({arr[r][c+1],r,c+1});
    }
    return res;
}