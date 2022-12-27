#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string smallestNumber(int S, int D){
        string num;
        for(int i=0;i<D;i++) num.push_back('0');
        if(S==0) return D ? num :"-1";
        if(S> 9*D) return "-1";
        num[0] = '1';
        int curr = 1;
        
        for(int i = D-1;i>=0;i--){
            if(curr + 9 < S){
                num[i] = '9', curr += 9;
            }else{
                num[i] += S - curr;
                curr = S;
                break;
            }
        }
        return curr == S ? num : "-1"; // now no need to check in end;
    }
};