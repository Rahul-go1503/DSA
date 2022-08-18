#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        unordered_map<char, int> T = { { 'I' , 1 },{ 'V' , 5 },{ 'X' , 10 },{ 'L' , 50 },{ 'C' , 100 },{ 'D' , 500 },{ 'M' , 1000 } };

        cout<<m['I']<<endl;
        cout<<s[0]<<endl;
        cout<<m[s[0]]<<endl;
        int ans =0;
        int size= s.length();
        for(int i=0;i<size-1;i++){
            if(m[s[i]] < m[s[i+1]]){
                ans-=m[s[i]];
            }else ans+=m[s[i]];
        }

        return ans + m[s[size-1]];
    }
int main(){
    string s="MCMXCIV";
    cout<<"ans is : "<<romanToInt(s)<<endl;
}