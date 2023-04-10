#include <bits/stdc++.h>
using namespace std;
/*
 - My soln by pf
 - TC - 

 - BY gcd
 - we have to find x such that it can divide every freq means we have to find gcd of all freq
*/
class Solution {
    // without calculating all pf we can do
    unordered_set<int> primeFac(int n){
        unordered_set<int> pf;
        while(n%2==0){
            pf.insert(2);
            n /=2;
        }
        for(int i=3;i*i<n;i+=2){
            // while(n%i) -> still passed 73/74 test cases lol.
            while(n%i==0){
                pf.insert(i);
                n /=i;
            }
        }
        if(n>2) pf.insert(n);
        return pf;
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();

        unordered_map<int,int> freq;
        int mn = n+1;
        for(auto &num : deck){
            freq[num]++;
            // mn = min(mn,freq[num]);
        }
        for(auto &p: freq){
            mn = min(mn,p.second);
        }
        unordered_set<int> pf = primeFac(mn);
        // loop here for i=2 to i=x 
        for(auto &x : pf){
            bool flag = true;
            for(auto &p : freq){
                if(p.second % x){
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};
// lee25 TC - O(N)
bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> count;
    int res = 0;
    for (int i : deck) count[i]++;
    for (auto i : count) res = __gcd(i.second, res);
    return res > 1;
}