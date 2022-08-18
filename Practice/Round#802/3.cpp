/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void print(vector<long long int> &v){
    for(auto val: v) cout<<val<<" ";
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long int n,ans=0;
        cin>>n;
        vector<long long int> arr;
        for(int i=0;i<n;i++){
            long long int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        // print(arr);
        for(int i=1;i<n;i++){
            long long int temp=arr[i];
            if(temp>0){
                for(int j=i;j<n;j++){
                    arr[j]-=temp;
                }
                    ans+=temp;
                cout<<"1st"<<ans<<endl;
            print(arr);
            }else if(temp<0){
                for(int j=0;j<n;j++){
                    arr[j]-=temp;
                }
                    ans-=temp;
                cout<<"2nd "<<ans<<endl;
            print(arr);
            }else{
                cout<<"3rd "<<ans<<endl;
            print(arr);
            }
        }
        for(int i=n-1;i>=0;i--){
            long long int temp=arr[i];
            if(!temp) continue;
            else{
               for(int j=i;j>=0;j--){
                    arr[j]-=temp;
                }
                    ans+=temp;
                cout<<ans<<endl;
                print(arr);
            }
        }
        cout<<ans<<endl;
    }
}