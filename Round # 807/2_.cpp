/*********************************************************************************************

Question :


Notes :
4
3
2 0 0
5
0 2 0 2 0
6
2 0 3 0 4 6
4
0 0 0 10


3
5
11
0

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define  nitro() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    nitro();
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        long long int cnt=0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>a;
            v[i]=a;
        }
        for(int i=0;i<n;i++){
            if(v[i]==0&&i-1>=0&&v[i-1]>=1){
                v[i]=1;
                v[i-1]--;
                cnt++;
                if(v[i-1]==0){
                    int j=i-1;
                    v[j]=1;
                    // cnt--;
                    while(j>=0&&v[j]==1){
                        j--;
                        // cnt++;/
                    }
                    if(j<0){
                        v[0]=0;
                    }
                    else if(v[j]!=1){
                        v[j]--;
                        // cnt++;
                    }
                }
            }
        }
        for(int i=0;i<n-1;i++){
            cnt+=v[i];
        }
        cout<<cnt<<endl;
    }
}