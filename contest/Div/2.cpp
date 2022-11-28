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
        int n,i;
        cin>>n;
        string t,ans;
        cin>>t;
        for(i=n-1;i>=0;i--){
            if(t[i]!='0'){
                ans.push_back((t[i]-'1') + 'a');
            }
            else{
                char c = 'a' + ((t[i-2]-'0')*10 + (t[i-1]-'0')-1);
                ans.push_back(c);
                i-=2;
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}