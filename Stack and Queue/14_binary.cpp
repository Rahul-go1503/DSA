#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()
vector<string> generate(int N)
{
    queue<string> q;
    vector<string> ans;
    q.push("1");
    int t = N; 
    while(t--){
        string s = q.front();
        ans.push_back(s);
        q.pop();
        int n = q.size()+ ans.size();
        if(n<N) {q.push(s+"0");n++;}
        if(n<N) q.push(s+"1");
    }
    return ans;
}