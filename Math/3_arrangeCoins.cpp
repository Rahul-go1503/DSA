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

// logN , 1;
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
// TC - sqrt(N)
/*
Isn't the first iterative solution time complexity also O(Sqrt(N))? Assume we have k as result, 1+2+...+k = N, then k(k+1) = 2N => 
k^2 = N => k = Sqrt(N)
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int r = 1;
        while(n-r>=0) n -= r++;
        return r-1;
    }
};
/*
The constraint of the problem can be expressed as follows:
k(k+1)≤2N
This could be solved by completing the square technique,

(k+ 1/2)^2 − 1/4  ≤ 2N
that results in the following answer:
k = sqrt(2N + 1/4)-1/2;
*/

// O(1),O(1)
class Solution {
public: 
    int arrangeCoins(int n) {
    return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
  }
};

/*
https://leetcode.com/problems/arranging-coins/solutions/1559913/java-3-solutions-bit-manipulation-binary-search-math-tc-o-1-sc-o-1-beats-100/?orderBy=most_votes

check official soln
*/
int arrangeCoins(int n) {
    int mask = 1 << 15;
    long result = 0;
    while (mask > 0) {
        result |= mask;
        if (result * (result + 1) / 2 > n) {
            result ^= mask;
        }
        mask >>= 1;
    }
    return (int) result;
}