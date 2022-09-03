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
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int i=0;
        while(i<n){
            if(s1[i]==s2[i]){
                i++;
                continue;
            }
            if(s1[i]=='G' || s1[i]== 'B'){
                if(s2[i]=='G' || s2[i]=='B'){
                    i++;
                }else{
                    cout<<"NO"<<endl;
                    break;
                }
            }else{
                cout<<"NO"<<endl;
                break;
            }
        }
        if(i==n) cout<<"yes"<<endl;
    }
}