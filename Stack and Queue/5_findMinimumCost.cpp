#include <bits/stdc++.h> 
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(N), SC - O(1)
int findMinimumCost(string str) {
    int cnt = 0;
    stack<char>st;
    for(auto &ch : str){
        if(ch=='{') st.push(ch);
        else if(st.empty()){ st.push('{');cnt++;}
        else st.pop();
    }
    if(st.size()%2!=0) return -1;
    else return cnt + st.size()/2;
}
// O(N),O(1);
int countRev (string s)
{
    int cnt = 0;
    int st = 0;
    for(auto &ch : s){
        if(ch=='{') st++;
        else if(st==0){ st++;cnt++;}
        else st--;
    }
    if(st%2!=0) return -1;
    else return cnt + st/2;
}