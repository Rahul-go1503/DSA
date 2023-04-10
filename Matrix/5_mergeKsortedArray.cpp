#include<bits/stdc++.h>
using namespace std;

// intriewbit AC
// coding ninja 10/11 TLE
vector<int> solve(vector<vector<int> > &arr) {
    int k = arr.size();
    int n = arr[0].size();
    
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    vector<int> merge;

    for(int i=0; i<k;i++){
        pq.push({arr[i][0],i,0});
    }
    while(pq.size()){
        vector<int> v = pq.top();
        int val = v[0];
        int r = v[1];
        int c = v[2];
        pq.pop();
        merge.push_back(val);
        if(c + 1 < arr[r].size()) pq.push({arr[r][c+1],r,c+1});
    }
    return merge;
}
