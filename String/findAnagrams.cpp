/*********************************************************************************************

Question :
1423. Maximum Points You Can Obtain from Cards

Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m;
        vector<int> ans;
        int k= p.length();
        for(int i=0;i<k;i++){
            m[p[i]]++;
        }
        int i=0;
        int j=0;
        int count = m.size();
        while(j<s.length()){
            //calculation
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0)
                    count--;
            }
            if(j-i+1<k){ // window not reach
                j++;
            }else{
                //ans from calculation
                if(count==0){
                    ans.push_back(i);
                    m[s[i]]++; //sliding window
                    if(m[s[i]]==1)
                            count++;
                }else{
                    //slinding window
                    if(m.find(s[i])!=m.end()){
                        m[s[i]]++;
                        if(m[s[i]]==1)
                            count++;
                    }
                }
                i++;j++;
            }
        }
        return ans;
    }
};