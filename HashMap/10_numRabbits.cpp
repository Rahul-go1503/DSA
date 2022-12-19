#include <bits/stdc++.h>
using namespace std;
/*
 - we have to find min rabbits in a forest based on the answers given by n rabbits
 - min would be n if all say 0 so we are calculating extra kitne ho skte hai n ke above
 - 
 - if ans is zero means he is only rabbit 
*/
class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int n = ans.size();
        unordered_map<int,int> ansFreq;
        for(auto &a : ans){
            // jab a+1 rabbits ne bol diya a or hai means sbhi array me hi hai(already count by n) so reset now
            if(ansFreq[a]==a+1) ansFreq[a] = 0;
            ansFreq[a]++;
        }

        int mnRab = 0;
        // ignore zero wale as they are already take in consideration(n)
        for(auto &p : ansFreq) if(p.first != 0) mnRab += p.first + 1 - p.second;
        return n + mnRab;
    }
};

// single pass
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty()) return 0;
        unordered_map<int,int> m;
        int res=0;
        for(int a:answers){
            if(a==0) res++;
            else{
                if(m[a]==0) res+=a+1;
                m[a]++;
                if(m[a]==a+1) m[a]=0;
            }           
        }
        return res;
    }
};