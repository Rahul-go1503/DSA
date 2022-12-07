#include <bits/stdc++.h>
using namespace std;

// simple BFS searching the path to last node 
// unweighted graph
// O(mn^2) => V = N^2 = (10000)^2 => 10^8 => TLE ?? think about it
// TLE nhi aayega kyuki ek node par at most 1 baar hi ja rhe hai grid[i][j] = 1; so => O(n*n)= 100 *100;
// and bfs me jese hi que me push kro tbhi vis true kr dena chaiye taki usi ka koi sibling bhi use fir se touch na kr pay
// otherwise ek hi node multi times que me push hoga = > TLE

// 2D BFS 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int lv = 0;
        while(q.size()){
            int sz = q.size();
            lv++;
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i==n-1 && j==n-1) return lv;

                vector<int> dir={-1, -1, 1, 1, -1, 0, 1, 0, -1};
                for(int k=0;k<8;k++){
                    int r = i + dir[k];
                    int c = j + dir[k+1];
                    if(r<0 || r>=n || c<0 || c>=n || grid[r][c]) continue;
                    q.push({r,c});
                    grid[r][c] = 1;
                }
            }
        }
        return -1;
    }
};


// recode once again 
class Node {
public:
    int x; int y; int d;
    Node(int dis,int i ,int j){
        d=dis;
        x=i;
        y=j;
    }
};
bool operator>(const Node& n1, const Node& n2)
{
    return n1.d > n2.d;
}
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0] = 1;
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        // i ,j
        pq.push(Node(1,0,0));
        while(pq.size()){
            int i = pq.top().x;
            int j = pq.top().y;
            pq.pop();
            if(i==n-1 && j==n-1) return dis[n-1][n-1];

            grid[i][j] = 1;

            vector<int> dir={-1, -1, 1, 1, -1, 0, 1, 0, -1};
            for(int k=0;k<8;k++){
                int r = i + dir[k];
                int c = j + dir[k+1];
                if(r<0 || r>=n || c<0 || c>=n || grid[r][c]) continue;
                if(dis[i][j]+1<dis[r][c]){
                    dis[r][c] = dis[i][j]+1;
                    pq.push(Node(dis[r][c],r,c));
                }
            }

        }
        return -1;
    }
};