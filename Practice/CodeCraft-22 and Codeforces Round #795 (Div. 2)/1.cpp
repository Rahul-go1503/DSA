#include <iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,even=0,odd=0;
        cin>>n;
        vector<int> arr;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            arr.push_back(temp);
        }
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                even++;
            }else odd++;
        }
        if(even>=odd) cout<<odd<<endl;
        else cout<<even<<endl;
    }
}