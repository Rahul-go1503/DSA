#include <bits/stdc++.h>
using namespace std;


// TC - n*log(log(n))
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> primes;
        int vis[N+1] = {};
        for(int i=2;i<=N;i++){
            if(vis[i]) continue;
            for(int j = i*i;j<=N;j+=i){
                vis[j] = 1;
            }
        }
        
        for(int i=2;i<=N;i++){
            if(!vis[i]) primes.push_back(i);
        }
        return primes;
    }
};