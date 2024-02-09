#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b){
    if(a==b) return 0;
    if(a>b) swap(a,b);
    return 1 + solve(b-a,a);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
}