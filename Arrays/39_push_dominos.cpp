#include <bits/stdc++.h>
using namespace std;

class Solution {
    // can do directly by string obj;
    void fill(int s, int e, string &ans, char a, char b){
        int n = e - s + 1,i=s;
        for(;n>=3 && i<=s + (n-3)/2;i++) ans[i] = a;
        if(a!=b && n%2==0) ans[i] = '.';
        else ans[i] = b;
        i++;
        for(;i<=e;i++) ans[i] = b;
    }
public:
    string pushDominoes(string dmnos) {
        int l = 0, n = dmnos.size();
        // int r = i+1;
        bool isR = false;

        string ans(n,'.');
        // for(int i=0;i<n;i++) ans.push_back('.');

        for(int i=0;i<n;i++){
            if(isR && dmnos[i] =='L'){
                fill(l,i,ans,'R','L');
                isR = false;
                l = i + 1;
            }
            else if(isR && dmnos[i]=='R'){
                fill(l,i,ans,'R','R');
                isR = true;
                l = i + 1;
            }
            else if(dmnos[i]=='L'){
                fill(l,i,ans,'L','L');
                isR = false;
                l = i + 1;
            }
            else if(dmnos[i] == 'R') ans[i] = 'R', l =i + 1,isR = true;
        }
        int i = n-1;
        while(isR && ans[i]=='.') ans[i--] = 'R';
        return ans;
    }
};

string pushDominoes(string d) {
    d = 'L' + d + 'R';
    string res = "";
    for (int i = 0, j = 1; j < d.length(); ++j) {
        if (d[j] == '.') continue;
        int middle = j - i - 1; // we are filling in between i & j
        if (i > 0)
            res += d[i];
        if (d[i] == d[j])
            res += string(middle, d[i]);
        else if (d[i] == 'L' && d[j] == 'R')
            res += string(middle, '.');
        else
            res += string(middle / 2, 'R') + string(middle % 2, '.') + string(middle / 2, 'L');
        i = j;
    }
    return res;
}