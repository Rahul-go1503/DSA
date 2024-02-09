#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    set<int> st;
    for(int i=0;i<n;i++){
        int sz = st.size();
        vector<int> temp;
        for(auto &x : st) temp.push_back(x);
        for(int k=0;k<sz;k++){
            st.insert(temp[k] + v[i]);
        }
        st.insert(v[i]);
    }
    cout<<st.size()<<endl;
    for(auto &x : st) cout<<x<<" ";
}