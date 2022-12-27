#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        int n = bills.size();
        mp[5],mp[10],mp[20];
        mp[bills[0]]++;
        for(int i = 1;i<n;i++){
            if(bills[i]==5) mp[5]++;
            else if(bills[i]==10){
                if(mp[5]) mp[5]--;
                else return false;
                mp[10]++;
            }else{
                if(mp[10] && mp[5]){
                    mp[10]--;
                    mp[5]--;
                }else if(mp[5]>=3) mp[5] -= 3;
                else return false;
                mp[20]++;
            }
        }
        return true;
    }
};

class Solution {
public: bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill: bills) {
            if (bill == 5)
                five++;
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};