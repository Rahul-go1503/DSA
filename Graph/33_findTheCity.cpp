#include <bits/stdc++.h>
using namespace std;

// Typical problem of Floyd warshall but can also be solved by Dijkstra
// O(n3) , O(n2);
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX)); // 1e9 or 10001 will work without check
        for(int i=0;i<n;i++) dis[i][i] = 0;

        for(auto &itr : edges){
            dis[itr[0]][itr[1]] = itr[2];
            dis[itr[1]][itr[0]] = itr[2];
        }

        for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
                    if(dis[i][k]==INT_MAX || dis[k][j]==INT_MAX) continue;
	                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);            
	            }
	        }
	    }

        int ans = 0 , mn = n;
        for(int i=0;i<n;i++){
            int cnt = 0;

            for(int j=0;j<n;j++){
                if(dis[i][j]<=th) cnt++;
            }

            if(cnt<=mn){
                mn = cnt;
                ans = i;
            }
        }

        return ans;
    }
};