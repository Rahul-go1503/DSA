#include<bits/stdc++.h>
using namespace std;

int calculateSquare(int a)
{
    int res = 0;
    a = abs(a);
    int b = a;
    while(b>0){
        if(b&1) res += a;
        a <<= 1;
        b >>= 1;
    }
    return res;
}