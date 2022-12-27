#include <bits/stdc++.h>
using namespace std;
/*
 - Use buckets to record the last position of digit 0 ~ 9 in this num
*/
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> buck(10,0);
        for(int i=0;i<n;i++) buck[s[i]-'0'] = i;
        
        for(int i = 0;i<n;i++){
            for(int j = 9;j>s[i]-'0';j--){
                if(buck[j]>i){
                    swap(s[i],s[buck[j]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};