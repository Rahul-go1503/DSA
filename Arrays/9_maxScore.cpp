/*********************************************************************************************

Question :
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array
cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
/*
- we have to choose total k cards
- step -1 assume all cards are from begining 
- step -2 remove one card from beg and add one card from end;
*/
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size()-1;
        int ans=0;

        for(int i =0;i<k;i++){
            ans+=cp[i];
        }
        
        int score = ans , s =0, e = n-1;
        for(int i=1;i<=k;i++){
            score = score - cp[s++] + cp[e--];
            ans = max(ans,score);
        }
        return ans;
    }
};

/*
 sliding window for min value of remening cards(n-k rem cards);
 - First make a window of size n-k then in next step slide the window
 - NOTE - Not a dp question 
*/
class Solution {
public:
    int maxScore(vector<int>& Points, int k) {
        int n = Points.size();
        int totPnt = 0 , remPnt = 0, mnRemPnt = 0;

        for(int i=0;i<n-k;i++) remPnt += Points[i];
        totPnt = mnRemPnt = remPnt;

        int s = 0;
        for(int i=n-k; i<n;i++)
            remPnt += - Points[s++] + Points[i],
            mnRemPnt = min(mnRemPnt, remPnt),
            totPnt += Points[i];

        return totPnt - mnRemPnt;  
    }
};