/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Not accepted but solved now
int main()
{
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        int cnt=n;
        // char c = s[0];
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                cnt+=i;
                // c=s[i];
            }
        }
        cout<<cnt<<endl;
    }

}