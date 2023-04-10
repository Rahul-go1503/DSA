#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1000000007;
class Solution{
	public:
	int TotalWays(int N)
	{
	    ll build = 1, space = 1;
	    for(int i=2;i<=N;i++){
	        ll temp = space;
	        space = (space + build)%mod;
	        build = temp;
	    }
	    ll res = (build + space)%mod;
	    return res*res%mod;
	}
};