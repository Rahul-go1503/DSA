/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// void solve(int a ,int b,string &ans){
//     for(int i=1;i<a;i++){
//                 ans.push_back('0');
//             }
//             for(int i=1;i<=b;i++){
//                 ans.push_back('1');
//             }
// }


// https://codeforces.com/profile/Suika-chan   view profile once
void solve() {
    int a, b;
    cin >> a >> b;
    while (a && b) {
        cout << 10;
        a--, b--;
    }
    while (a) {
        cout << 0;
        a--;
    }
    while (b) {
        cout << 1;
        b--;
    }
    cout << '\n';
}

int main()
{
    int t,a,b;
    cin>>t;
    while(t--){
        string ans;
        cin>>a>>b;
        if(a>=b){
            for(int i=1;i<=b;i++){
            ans.push_back('0');
            ans.push_back('1');
            }
            for(int i=1;i<=a-b;i++){
                ans.push_back('0');
            }
        }else{
            for(int i=1;i<=a;i++){
            ans.push_back('1');
            ans.push_back('0');
            }
            for(int i=1;i<=b-a;i++){
                ans.push_back('1');
            }

        }
        cout<<ans<<endl;
    }
}