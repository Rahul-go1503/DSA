#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;

/*
    0 - 0 - 0,1
        1 - 0

    1 - 0 - 0,1

    zero - count of string ending with 0;
    one - count of string ending with 1;
*/
class Solution{
public:	
	ll countStrings(int n) {
	    ll zero = 1, one = 1;
	    for(int i=2;i<=n;i++){
	        ll temp = zero;
	        zero = (zero + one)%mod;
	        one = temp;
	    }
	    return (zero + one)%mod;
	}
};