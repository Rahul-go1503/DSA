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
int main(){
    string s ="FXSHRXW";
    cout<<titleToNumber(s)<<endl;
}