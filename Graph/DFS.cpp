/*********************************************************************************************

Question :


Notes :
Adjecncy List of weighted graph
array of vectors
vector<pair<int,int> adjList []
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/***
 * First two action are --- jab niche ja rhe hai
 * last two action are --- jab uper aa rhe hote hai
 ***/


//DFS Search
void  dfs(int vertex , vector<int> & visited , vector<pair<int,int>> adjList[]){
    /* Take action on vertex after entering the vertex*/
    if(visited[vertex]) return ; // return if alreadt visited
    visited[vertex]= true; // mark the vertex visited
    for( pair<int,int> nbr : adjList[vertex]){ 
        /*Take action on child before entering the child node*/
        dfs(nbr.second,visited,adjList); // dfs for neighbours
        /*Take action on child after exiting the child node*/
    }
    /*Take action on vertex before exiting the vertex*/
}
// Time Complex - O(V+E);
