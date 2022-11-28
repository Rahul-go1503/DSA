#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O()
	Space Complexity: O()
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        int i = lower_bound(sat.begin(),sat.end(),0)-sat.begin();
        
        if(i==n) return 0;

        int sum = 0,coeff = 0,t=1;
        for(int k = i;k<n;k++){
            sum+=sat[k];
            coeff+=sat[k]*t++;
        }
        for(int k = i-1;k>=0 && sum + sat[k]>0;k--){
            sum+=sat[k];
            coeff+=sum;
        }
        return coeff;
    }
};

class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        int sum = 0,coeff = 0;
        for(int k = n-1;k>=0 && sum + sat[k]>0;k--){
            sum+=sat[k];
            coeff+=sum;
        }
        return coeff;
    }
};