#include <bits/stdc++.h>
using namespace std;

/*
 - O(1),O(1)
 - Accepted after 6 unsuccessful attempt.
*/
class Solution{
public:
    int minimumDays(int S, int N, int M){
        if(N<M || N==M && S>=7) return -1;
        if(N==M && S<7) return S;
        int d = M*S/N + (M*S%N ? 1 : 0);
        return d<=S - S/7 ? d : -1;
    }
    
};

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // If we can not buy at least a week
        // supply of food during the first week
        // OR We can not buy a day supply of food
        // on the first day then we can't survive.
        if (((N * 6) < (M * 7) && S > 6) || M > N)
        	return -1;
    	else{
    	    // If we can survive then we can
        	// buy ceil(A/N) times where A is
        	// total units of food required.
        	int days = (M * S) / N;
        	if (((M * S) % N) != 0)
        		days++;
        	return days;
    	}
    }
};