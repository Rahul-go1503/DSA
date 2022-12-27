#include <bits/stdc++.h>
using namespace std;

// O(n2),O(k) - without using the fact that elem are sorted
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto &r : matrix){
            for(auto &cell : r){
                if(pq.size()<k) pq.push(cell);
                else if(cell < pq.top()) pq.pop(), pq.push(cell);
            }
        }
        return pq.top();
    }
};