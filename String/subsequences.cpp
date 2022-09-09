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

void subsequences(string str,string sub , vector<string> &ans, int idx= 0 ){
    if(!sub.empty()) ans.push_back(sub);
    for(int i = idx;i<str.length();i++){
        subsequences(str,sub+str[i],ans,i+1);
    }
}
vector<string> subsequences(string str){
    vector<string> ans;
    subsequences(str,"",ans);
    return ans;
}


void subsequences2(string str,string sub , vector<string> &ans, int idx= 0 ){
    if(idx==str.length()){
        if(!sub.empty()) ans.push_back(sub);
        cout<<sub<<" "<<ans.back()<<endl;
        return;
    } 
    subsequences2(str,sub,ans,idx+1);
    subsequences2(str,sub+str[idx],ans,idx+1);
}
vector<string> subsequences2(string str){
    vector<string> ans;
    subsequences2(str,"",ans);
    return ans;
}

int main(){
    vector<string> ans = subsequences2("abc");
    for(int i =0;i<ans.size();i++) cout<<ans[i]<<endl;
}