#include <bits/stdc++.h>
using namespace std;
/*?
 - vey imp
 - ask in interview and OA
 - dynamic graph
 - findPar and union two funct 
 - rank is related to tree height
 - findPar will take log(N) - memo
 - both rank and size have same T.C
 - 
*/
/*
    1. Why connect smaller compo to larger compo ?
    2. why path comparsion ?   nothing but memo
    3. TC - 4*alpha ~= constant
    4. we understand this by tree but we are not actually building any tree, we are just playing with parent and 
       to decide who will be next parent we use either rank or size array.(we want to do is minimize
       the height of the resulting tree)
    5. parent is also know as representive of that set or group
    6. Uses - 
        we can tell whether u and v are from same grp or not in O(1);
      brute force - dfs. bfs => (V+E);

Time: O(n + m*α(n)) ≈ O(n + m), m is the length of connections (union operations).
Explanation: Using both path compression and union by size ensures that the amortized time per operation is only α(n), which is optimal, where α(n) is the inverse Ackermann function. This function has a value α(n) < 5 for any value of n that can be written in this physical universe, so the disjoint-set operations take place in essentially constant time.
Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure or https://www.slideshare.net/WeiLi73/time-complexity-of-union-find-55858534 for more information.
Space: O(n)



1) DSU extra edge of same component ko ignore karta hai
2) DSU minimum edge ka connected graph hota hai ( for visualization )
3) component of graph ki bat ho rahi think of DSU once
*/

class DisjointSet{
    int node,cnt,cntUn;
    vector<int> rank, size, parent;
public:
    DisjointSet(int n){
        cnt = node = n;
        cntUn = 0;
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }
    // find ultimate parent not parent
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findPar(u) , pv = findPar(v);
        if(pu==pv) return;

        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
        cnt--;
        cntUn++;
    }

    void unionBySize(int u, int v){
        int pu = findPar(u) , pv = findPar(v);
        if(pu==pv) return;

        if(size[pu]<size[pv]){
             parent[pu] = pv;
             size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] +=size[pv];
        }
    }

    int countSet() {return cnt;}
    int countUnion() {return cntUn;}
    int sizeofSet(int u) {return size[findPar(u)];}
};
