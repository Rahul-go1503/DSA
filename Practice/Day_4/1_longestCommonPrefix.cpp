#include<bits/stdc++.h>
using namespace std;
// bool cmp(string s1,string s2){
//     return s1.length()<s2.length();
// }
string longestCommonPrefix(vector<string>& strs) {
        string ans ="";
        bool hasChar= true;
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].length();i++){
            for(int j=0;j<strs.size();j++){
                if(strs[0][i]!=strs[j][i]){
                    hasChar=false;
                }
            }
            if(hasChar) ans.push_back(strs[0][i]);
        }
        return ans;
    }

int main(){
    vector<string> strs ={"flower","flow","floight","d"} ;
    cout<<"ans is : "<<longestCommonPrefix(strs)<<endl;
}