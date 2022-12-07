#include <bits/stdc++.h>
using namespace std;

/*
 NOTES : 
 1. TC - O(N3);
 2. Sc - O(1) if in place ( Wrong ) - O(N*N);
 3. can detect neg cycle
 4. intuition is mainly brute force
 5. if we dont have neg cycle then dijkstra is still better O(V * ELog V)
 6. If interviewer ask then must tell these type of points not just tell the algo
 7. If graph is UG then converted to DG

 1. why Dijkstra will not work?
 2. How you can detect neg cycle?
 3. What if you have neg cycle?
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){
	    int n = mat.size();
	    // Step 1: Initialization
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(i==j) mat[i][i]=0;
	            if(mat[i][j]==-1){
	                mat[i][j] = 1e9;
	            }
	        }
	    }
	    
        // Step 2: Calculation
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);            
	            }
	        }
	    }
	    
        // Step 3: detect neg cycle
        for(int i=0;i<n;i++){
            if(mat[i][i]<0){
                // we have neg cycle
            }
        }

        // as we are doing in- place so this addinatiol step
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(mat[i][j]==1e9){
	                mat[i][j] = -1;
	            }
	        }
	    }
	}
};