#include <bits/stdc++.h>
using namespace std;

/*
Continuously replace n with the sum of its prime factors.

Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
Return the smallest value n will take on.
2<=n<=10^5
*/
class Solution {
    int sumOfPF(int n){
        int s = 0,d=2;
        while(n>1){
            if(n%d==0) n /=d, s += d;
            else d++;
        }
        return s;
    }
public:
    int smallestValue(int n) {
        int sum = sumOfPF(n);
        if(sum==n) return n;
        else return smallestValue(sum);
    }
};

// 2<=n<=10^5
class Solution {
public:
    int smallestValue(int n) {
        while(true){
            int val = n,sum = 0, d = 2;
            while(n>1){
                if(n%d==0) n/=d, sum += d;
                else d++;
            }
            if(sum == val) return sum;
            else n = sum;
        }
    }
};