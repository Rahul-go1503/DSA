#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O()
	Space Complexity: O()
*/

class Solution {
    bool isEqual(unordered_map<char,int> &m, unordered_map<char,int> &m2){
        for(auto itr = m2.begin();itr!=m2.end();itr++){
            if(itr->second != m[itr->first]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        int n1 = s1.length(), n2 = s2.length();
        for(int i=0;i<n1;i++) m[s1[i]]++;
        int k = 0,s=0,len=0;
        unordered_map<char,int> m2;
        while(k<n2){
            if(len==n1){
                if(isEqual(m,m2)) return true;
                m2[s2[s]]--;
                s++;
                len--;
            }
            if(m.find(s2[k])!=m.end()){
                m2[s2[k]]++;
                len++;
            }else{
                s=k+1;
                len=0;
                m2.clear();
            }
            k++;
        }
        if(len==n1 && isEqual(m,m2)) return true;
        return false;
    }
};