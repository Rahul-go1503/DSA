/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        string s;
        cin>>n>>s;
        if(n!=5){
             cout<<"No"<<endl;
             continue;
        }
        unordered_set<char> hash = {'T','i','m','u','r'};
        for(i=0;i<n;i++){
            if(hash.find(s[i])==hash.end()){
                cout<<"No"<<endl;
                break;
            }
        }
        if(i==n) cout<<"Yes"<<endl;
    }
}