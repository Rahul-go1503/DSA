#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    int indeg[V]={};
	    for(int u=0;u<V;u++){
	        for(auto &v : adj[u]){
	            indeg[v]++;
	        }
	    }
	    
	    for(int u=0;u<V;u++){
	        if(indeg[u]%2) return false;
	    }
	    return true;
	}
};