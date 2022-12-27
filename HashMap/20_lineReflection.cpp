#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
bool lineReflection(vector<vector<int>>& pts)
{
	unordered_map<int,vector<int>> mp;
    for(auto &p : pts){
        mp[p[1]].push_back(p[0]);
    }
    double mid = INT_MIN;
    
    for(auto &itr : mp){
     // int y = itr.first;
        auto vx = itr.second;
        sort(vx.begin(), vx.end());
        int s = 0, e = vx.size()-1;
        while(s<=e){
            while(s<=e && vx[s]==vx[s+1]) s++;
            while(s<=e && vx[e]==vx[e-1]) e--;
            double temp = (vx[e] - vx[s])/2.0 + vx[s];
            if(mid == INT_MIN) mid = temp;
            else if(temp != mid) return false;
            s++,e--;
        }
    }
    return true;
}


#include <bits/stdc++.h> 
bool lineReflection(vector<vector<int>>& pts)
{
	unordered_map<int,set<int>> mp;
    for(auto &p : pts){
        mp[p[1]].insert(p[0]);
    }
    double mid = INT_MIN;
    
    for(auto &itr : mp){
     // int y = itr.first;
        auto sx = itr.second;
        while(sx.size()){
//             cout<<sx.size()<<endl;
            auto s = sx.begin(), e = --sx.end();
//             cout<<*s<<" "<<*e<<endl;
            double temp = (*e - *s)/2.0 + *s;
            if(mid == INT_MIN) mid = temp;
            else if(temp != mid) return false;
            sx.erase(s);
            if(e != s)sx.erase(e);
        }
    }
    return true;
}
