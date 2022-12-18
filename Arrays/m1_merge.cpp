/*********************************************************************************************

Question :
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Notes :

**********************************************************************************************/

/*
	Time Complexity: O(nlogn)
	Space Complexity: O(1)
*/

// once go through the graph based solution mention in leetcode official soln and BST also
// https://leetcode.com/problems/merge-intervals/solutions/355318/fully-explained-and-clean-interval-tree-for-facebook-follow-up-no-sorting/?orderBy=most_votes
// Interval tree
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        int i=0,j=i;
        vector<vector<int>> merged;
        sort(inter.begin(),inter.end());
        while(j<n){
            int f = inter[i][0];
            int s = inter[i][1];
            j++;
            while(j<n && inter[j][0]<=s){
                if(inter[j][1]>=s){
                    s = inter[j][1];
                }
                j++;
            }
            merged.push_back({f,s});
            i=j;
            
        }
        return merged;
    }
};

 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(output.back()[1] >= intervals[i][0]) output.back()[1] = max(output.back()[1] , intervals[i][1]);
            else output.push_back(intervals[i]); 
        }
        return output;
    }