#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O(exp) ,1 <= n <= 30
	Space Complexity: O(1)
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string temp = countAndSay(n-1);
        string ans; int s = temp.length();
        // cout<<n<<" -> temp : "<<temp<<" "<<endl;
        for(int i=0;i<s;i++){
            int j = i+1;
            while(j<s && temp[j]==temp[i]) j++;
            ans.push_back(j-i+'0'); ans.push_back(temp[i]);
            // cout<<ans<<endl;
            i=j-1;
        }
        return ans;
    }
};