#include<bits/stdc++.h>
using namespace std;

// cost of painting curr house is - 
/*
    if we paint with clr 0 => then prev house should be clr with 1 or 2 we need to take min of them;
    as we are calculating cost for painting house i with clr 0,1 and 2, we will take min of them
*/
int minCost(vector<vector<int>> &cost)
{
	int prev = 0, prev1 = 0, prev2 = 0;
	for(auto &v : cost){
		int curr = v[0] + min(prev1,prev2);
		int curr1 = v[1] + min(prev,prev2);
		int curr2 = v[2] + min(prev,prev1);
		prev = curr, prev1 = curr1, prev2 = curr2;
	}
	return min(prev,min(prev1,prev2));
}