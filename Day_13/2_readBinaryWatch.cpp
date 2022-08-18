/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
void solve(vector<string> &ans,string time, int n){
    if(n==0){
        ans.push_back(time);
        return;
    }

}
vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    if(turnedOn>8) return ans;
    string time;
    solve(ans,time,turnedOn);
    return ans;       
}
int main()
{
}