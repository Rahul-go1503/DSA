#include<bits/stdc++.h>
using namespace std;

void rec(string s,vector<string> &res, string curr = "", int i=0)
{
   int n = s.length();
   if(i==n){
       res.push_back(curr);
       return;
   }
   
   rec(s,res,curr,i + 1);
   curr.push_back(s[i]);
   rec(s,res,curr,i + 1);
}

vector <string> powerSet(string s){
    vector<string> res;
    rec(s,res);
    return res;
}