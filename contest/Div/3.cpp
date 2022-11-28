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

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int m = 0,n= s.length();
        map<int,vector<int>> mp;
        int tcost = s[n-1]-s[0];
        char c1,c2;
        if(tcost>=0){
            c1 = s[0];
            c2 = s[n-1];
        }else{
            c1 = s[n-1];
            c2 = s[0];
        }
        for(int i=0;i<n;i++){
            if(s[i]-c1>=0 && s[i]<=c2) m++;
            mp[s[i]-'a'].push_back(i+1);
        }
        cout<<abs(tcost)<<" "<<m<<endl;
        auto itr = mp.find(s[0]-'a');
        auto end = mp.find(s[n-1]-'a');
        for(int j = 0;j<mp[s[0]-'a'].size();j++){
            // cout<<"1st"<<endl;
            cout<<mp[s[0]-'a'][j]<<" ";
        }
        if(tcost>0){
            end++;
            // cout<<"2nd"<<endl;
            for(auto i = ++itr;i!=end;i++){
                int size = i->second.size();
                for(int j = 0;j<size;j++){
                    cout<<mp[i->first][j]<<" ";
                }
            }
        }else if(tcost<0){
            // cout<<"3rd"<<endl;
            end--;
            for(auto i = --itr; i!= end;i--){
                int size = i->second.size();
                for(int j = 0;j<size;j++){
                    cout<<mp[i->first][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
}