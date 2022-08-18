#include <bits/stdc++.h>
using namespace std;
int arrangeCoins(int n) {
    int i=0;
     while(n>0){
         n-=i+1;
         if(n>=0) i++;
         cout<<n<<" "<<i<<"\n";
     }
     cout<<endl;
     return i;   
    }
int arrangeCoins2(int n) {
    int s=1;
    int e=n;
    while(s<=e){
    int mid=s+(e-s)/2;
    long long sum= 1LL*mid*(mid+1)/2;
    if (sum == n)
        return mid;
    else if (sum > n)
        e = mid - 1;
    else
        s = mid+1;
    }
    return e;
    }

    int main(){
        int n=5;
        cout<<arrangeCoins2(n)<<endl;
    }