/*********************************************************************************************

Question : Ninja And The Fence


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int numberOfWays(int n, int k) {
    if(n==1) return k;
    long long prev2 = k, prev1 = (k*k)%mod;
    for(int i=3;i<=n;i++){
        int curr = ((k-1)*(prev1+prev2)%mod)%mod;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int add ( int a ,int b){
    return (a%mod + b%mod)%mod;
}
int mul (int a , int b){
    return ((a%mod)*1LL*(b%mod))%mod;
    // return a%mod*1LL*(b%mod)%mod;
}
int numberOfWays2(int n, int k) {
    int prev2 = k;
    int prev1 = add(k, mul(k,k-1));
    for(int i=3;i<=n;i++){
        int curr = add(mul(prev1,k-1),mul(prev2,k-1));
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    cout<<numberOfWays2(3,2)<<endl;
}