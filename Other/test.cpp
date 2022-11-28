/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int returnMaxMin(int n){
    if(n>2) return INT_MIN;
    // return INT_MAX;
    return INT_MIN;
}
#define mod 1000000007
int main()
{
    // cout<<10%10<<endl;
    // cout<<min(1,(int)(1-INFINITY))<<endl;
    // int max = INT_MAX;
    // int min = INT_MIN;
    // cout << max << min << endl;
    // int ans = returnMaxMin(5);
    // cout << ans << endl;
    // cout<<LLONG_MAX%1000000007<<endl;
    // cout<<(2147483647+0*1LL+1)%mod<<endl;
    // cout<<1LL<<endl;
    string s;
    s.push_back(1+'0');
    s.push_back('0'+2);
    cout<<s<<endl; // 12
    cout<<'a'-'a'<<endl; // 0
    cout<<'2'-'1'<<endl; // 1
    cout<<'2'+'1'<<endl; // 99
    cout<<int('0')<<endl; // 48
    int f  = '2'>'1' ? 1 : 0;
    cout<<f<<endl; // 1
}