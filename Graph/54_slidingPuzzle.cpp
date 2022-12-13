#include <bits/stdc++.h>
using namespace std;

// Error - AddressSanitizer
// and how u track visited boards ? so store boards in a string
// wrong approach coded below ->
#define vvi vector<vector<int>>
class Solution {
    bool isSolved(vvi &grid){
        vvi solved = {{1,2,3},{4,5,0}};
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                if(grid[i][j] != solved[i][j]) return false;
        return true;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vvi> q;
        q.push(board);
        int move = -1;
        while(q.size()){
            int sz = q.size();
            move++;
            while(sz--){
                vvi grid = q.front();
                q.pop();

                int i,j;
                for(i=0;i<2;i++)
                    for(j=0;j<3;j++)
                        if(grid[i][j]==0) break;

                int dir[] = {1,0,-1,0,1};
                for(int d=0;d<4;d++){
                    int r = i + dir[d];
                    int c = j + dir[d+1];
                    if(r<0 || c<0 || r>=2 || c>=3) continue;
                    swap(grid[i][j],grid[r][c]);
                    if(isSolved(grid)) return move + 1;
                    q.push(grid);
                    swap(grid[i][j],grid[r][c]);
                }
            }
        }
        return -1;       
    }
};


// Right ->
/*
m : no of rows , n : no of cols
Time Complexity: m*n*(m*n)!
Space Complexity: m*n*(m*n)!
There are at most 6! permutation of the 6 numbers: 0~5. For each permustion, cost spaceO(6); String find and equal
operation cost time O(6). Therefore, space and time both cost 6 * 6! = 4320.
In this specific case : 
6*(2*3)! & 6*(2*3)!
*/
#define vvi vector<vector<int>>
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<string> q;
        string src = "";
        string des = "123450";
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                src += to_string(board[i][j]);
        
        if(src == des) return 0;
        q.push(src);
        int move = -1;

        unordered_set<string> vis;
        vis.insert(src);
        while(q.size()){
            int sz = q.size();
            move++;
            while(sz--){
                string curr = q.front();
                q.pop();

                int zeroIdx = curr.find('0');
                vvi moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
                // 0 th index pr 0 h to vo sirf index 1 ya index 3 pe shift ho sakta hai and same for rest of index.

                for(auto &m : moves[zeroIdx]){
                    swap(curr[m],curr[zeroIdx]);
                    if(!vis.count(curr)){
                        if(curr == des) return move + 1;
                        q.push(curr);
                        vis.insert(curr);
                    }
                    swap(curr[m], curr[zeroIdx]);
                }
            }
        }
        return -1;       
    }
};