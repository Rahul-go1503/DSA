#include <bits/stdc++.h>
using namespace std;
void  dfs(int vertex , vector<int> & visited , vector<pair<int,int>> adjList[]){
    if(visited[vertex]) return ; // return if alreadt visited
    visited[vertex]= true; // mark the vertex visited
    for( pair<int,int> nbr : adjList[vertex]){ 
        dfs(nbr.second,visited,adjList); // dfs for neighbours
    }
}
void  dfsForCC(int vertex , vector<int> & visited , vector<pair<int,int>> adjList[] , vector<int> & current_cc){
    if(visited[vertex]) return ; // return if alreadt visited
    visited[vertex]= true; // mark the vertex visited
    current_cc.push_back(vertex);
    for( pair<int,int> nbr : adjList[vertex]){ 
        dfs(nbr.second,visited,adjList); // dfs for neighbours
    }
}

// count connected components

int connectedComponents(vector<int> & visited , vector<pair<int,int>> adjList[]){
    int cnt = 0 ;
    int n = adjList->size(); // exp??
    vector<vector<int>> cc; // store all connected components
    for(int i =0; i<n;i++){
        if(visited[i]) continue;
        vector<int> current_cc;
        dfsForCC(i,visited,adjList,current_cc);
        cc.push_back(current_cc);
        cnt++;
    }
    return cnt;
}