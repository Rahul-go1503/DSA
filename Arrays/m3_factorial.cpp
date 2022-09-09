#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O(N2)
	Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> fac;
        fac.push_back(1);
        for(int i=2;i<=N;i++){
            int n = fac.size(),carry=0;
            for(int j=0;j<n;j++){
                int sum = carry + fac[j]*i;
                fac[j] = sum%10;
                carry = sum/10;
            }
            while(carry){
                fac.push_back(carry%10);
                carry/=10;
            }
        }
        reverse(fac.begin(),fac.end());
        return fac;
    }
};