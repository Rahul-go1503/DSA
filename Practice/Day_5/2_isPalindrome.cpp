#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x)
{
    string s = to_string(x);
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return 0;
    }
    return 1;
}

// without string.... overflow considered -- if we traverse whole number than eq 1234567899 on reverse 9987654321 overflows 
bool isPalindrome2(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)  // imp
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }