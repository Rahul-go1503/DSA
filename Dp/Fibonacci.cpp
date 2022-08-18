/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O(N)
	Space Complexity: O(N)

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int fib(int n) {
        int prev2 = 0;
        int prev1 = 1;
        for(int i=2;i<=n;i++){
            int curr = prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return n==0? 0: prev1;
    }
};