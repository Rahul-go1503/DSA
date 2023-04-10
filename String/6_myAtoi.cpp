#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0, n = s.length(), res = 0, pos = 1;
        while(s[i]==' ') i++;
        if(s[i]=='-') pos = 0, i++;
        else if(s[i]=='+') i++;

        while(i<n && s[i] >= '0' && s[i] <= '9'){
            int dgt = s[i] - '0';
            if(res > (INT_MAX-dgt)/10 ){
                // cout<<res<<endl;
                res = INT_MAX;
                return pos ? res : -res-1;
            }else{
                res = res*10 + dgt;
            }
            i++;
        } 
        return pos ? res : -res;
    }
};