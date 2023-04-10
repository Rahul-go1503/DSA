#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int on = 0,ze = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') on++;
    }
    ze = n - on;
    
}