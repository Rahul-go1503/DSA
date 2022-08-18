/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n) {
    if(n<=0) return 0;
        int setbit=0;
        while(n){
            if(n&1) setbit++;
            n=n>>1;
        }
        return setbit==1?1:0;
    }
 bool isPowerOfTwo2(int n) {
        return n > 0 && !(n & n - 1);
    }
int main()
{
    cout<<"ans is "<<isPowerOfTwo2(9)<<endl;
}