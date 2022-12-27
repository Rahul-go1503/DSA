#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
    int n=0,temp=1;
    int s = columnTitle.length();
    for(int i=s-1;i>=0;i--){
        // cout<<columnTitle[i]<<endl;
        n= n+ (columnTitle[i]-'A'+1)*temp;
        // result = result* 26 + d
        if(temp<=INT_MAX/26) temp = temp*26;
        cout<<temp<<endl;
    }
    return n;
}
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int s = columnTitle.length();
        int n = columnTitle[s-1]-'A'+1, temp=1;
        
        for(int i=s-2;i>=0;i--){
            temp *= 26;
            n += (columnTitle[i]-'A'+1)*temp;
        }
        return n;
    }
};