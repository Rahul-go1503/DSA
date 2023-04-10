#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        cpp_int prev = 1;
        for(int i=1;i<=n;i++){
            cpp_int curr = 2*(2*i-1)*prev/(i+1);
            prev = curr;
        }
        return prev;
    }
};