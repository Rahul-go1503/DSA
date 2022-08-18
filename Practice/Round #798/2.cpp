/********************************************************************************************* 
 
Question : 


Notes : 

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


//  NOT solved

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            return;
        }
        vector<int> arr;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        int i=0;
        while(i<n){
            int temp=0;
            if(arr[i]!=i+1){
                i++;
            }else{
                for(int j=temp;j<i;j++){
                    ans.push_back(j);
                }
                ans.push_back(i);
                i++;
            }
        }
        if(ans.empty()){
            for(int i=1; i<=n;i++){
                ans.push_back(i);
            }
        }
    }
}