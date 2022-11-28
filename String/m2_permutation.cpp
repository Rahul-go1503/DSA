#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O(n*n!)
	Space Complexity: O(n)
*/

class Solution{
void permutation(string &s,set<string> &ans,int idx=0){
    ans.insert(s);
    int n = s.length();
	for(int i = idx;i<n;i++){
		swap(s[idx],s[i]);
		permutation(s,ans,idx+1);
		swap(s[idx],s[i]);
    }
}
	public:
		vector<string>find_permutation(string s)
		{
		    set<string> ans;
		    permutation(s,ans);
		    vector<string>res(ans.size());
		    auto itr = ans.begin();
		    for(int i=0;i<ans.size();i++) res[i]=*itr++;
		    return res;
		}
};