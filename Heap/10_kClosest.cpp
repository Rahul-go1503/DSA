#include <bits/stdc++.h>
using namespace std;

// Editorial rem
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> mxHp;
        for(auto &p : points){
            int cx = p[0], cy = p[1];
            int cd = cx*cx + cy*cy;
            if(mxHp.size()<k) mxHp.push({cd,cx,cy});
            else{
                auto tp = mxHp.top();
                int x = tp[1], y= tp[2];
                int d = x*x + y*y;
                if(d>cd){
                    mxHp.pop();
                    mxHp.push({cd,cx,cy});
                }
            }
        }
        vector<vector<int>> res;
        while(mxHp.size()){
            auto tp = mxHp.top();
            int x = tp[1], y= tp[2];
            res.push_back({x,y});
            mxHp.pop();
        }
        return res;
    }
};