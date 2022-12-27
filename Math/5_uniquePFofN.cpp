#include <bits/stdc++.h>
using namespace std;

/*
Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
 

Constraints:
1 <= N  <= 106
*/

// TC - logN ,O(1);
class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    vector<int> res;
	    int d = 2;
	    while(n>1){
	        if(n%d==0){
	            if(res.empty()) res.push_back(d);
	            else if(res.back() != d) res.push_back(d);
	            n /= d;
	        }else d++;
	    }
	    return res;
	}
};
