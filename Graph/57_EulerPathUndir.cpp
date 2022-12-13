#include <bits/stdc++.h>
using namespace std;

// Euler path - visit every edge exactly once
// Euler circuit - Euler path + src and sink must be same
class Solution{
public:
    // either 0 or exactly 2 odd nodes with indegree => eulerian path exist
    int eulerPath(int N, vector<vector<int>> graph){
        int indeg[N] = {};
        
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(graph[i][j]) indeg[i]++ , indeg[j]++;
            }
        }
        int oddCnt = 0;
        for(int i=0;i<N;i++){
            if(indeg[i]%2) oddCnt++;
        }
        
        if(oddCnt != 0 && oddCnt !=2) return 0;
        else return 1;
    }
};