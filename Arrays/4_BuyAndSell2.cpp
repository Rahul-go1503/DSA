/*********************************************************************************************

Question :
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However,
you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
Notes :
1. ek hi stock hai or same day par buy and sell dono kar skte hai
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Arrays
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit= 0;
        for(int i=0;i<n-1;i++){
            if(prices[i]<prices[i+1]){
                profit+=prices[i+1]-prices[i];
            }
        }
        return profit;
    }
};

int main()
{
}