#include <bits/stdc++.h>
using namespace std;

#define usi unordered_set<int>

// by prefix sum
// TC - posSum * n + NM 
// SC - M + sum {sum<=M }
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        vector<usi> pre(n);
        usi posbSum;
        int sum = 0;

        // storing prefix sum in each row and storing all possibe sum
        for(int i=0;i<n;i++){
            sum = 0;
            for(auto &w : wall[i]){
                sum += w;
                pre[i].insert(sum);
                posbSum.insert(sum);
            }
        }
        // cout<<sum<<endl;
        posbSum.erase(sum); // erasing last value as 0 and sum is not allowed

        int mx = n, curr;
        for(auto &val : posbSum){
            curr = 0;
            for(int i=0;i<n;i++){
                if(!pre[i].count(val)) curr++;  // if we could not find val means brick must be break
            }
            // cout<<curr<<endl;
            mx = min(mx,curr);
        }

        return mx;
    }
};
// much shorter by edges positions
// TC - MN
// SC - M where M - total no of bricks
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        unordered_map<int, int> edge_frequency;     //HashMap to store the number of common edges among the rows
        int max_frequency = 0;         //Variable to store the frequency of most occuring edge
        
        for(int row=0; row<wall.size(); row++)        //Iterating through each row
        {
            int edge_postion = 0;       //Variable to store different edge postion
            
            for(int brick_no=0; brick_no< wall[row].size() -1; brick_no++)    //Iterating through each brick inside a row
            { 
                int current_brick_length = wall[row][brick_no];  //Length of the current brick
                edge_postion = edge_postion + current_brick_length ;  //Next Edge Position = Previous Edge Position + Current Brick's Length
                edge_frequency[edge_postion]++;  //Incrementing the Frequency of just calculated Edge Postion
                max_frequency = max(edge_frequency[edge_postion],max_frequency);  //Comparing the "Frequency of just calculated Edge Postion" with "Max Frequency seen till now" & storing whichever is greater.
            }
        }
        return wall.size() - max_frequency; // returning (Number of Bricks Crossed by Line) i.e. (Number of Rows in Wall - Frequency of Most Occuring Edge) 
    }
};