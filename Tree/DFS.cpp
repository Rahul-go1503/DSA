/*********************************************************************************************

Question :


Notes :
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


//DFS Search For General Tree
void  dfs(int vertex , int par=0, vector<int> adjList[]){
    // if(vertex==par) return ; ....can do this also
    for(auto child : adjList[vertex]){ 
        if(child==par) continue; // reject call for parent only
        dfs(child,vertex,adjList); // dfs for neighbours
    }
}