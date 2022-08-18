/*********************************************************************************************

Question :
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size()-1;
        int cards = k;
        long long int ans=0;
        for(int i =0;i<cards;i++){
            ans+=cp[i];
        }
        long long int score = ans;
        for(int i=1;i<=cards;i++){
            score = score-cp[--k]+cp[n--];
            ans = max(ans,score);
        }
        return ans;
    }
};