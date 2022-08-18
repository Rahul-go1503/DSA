/*********************************************************************************************

Question :


DETAILED WHITEBOARD! BEATS 100% (Do you really want to understand It?)
Notes :
Logic:
I am already going to assume that you know about prefix sums before you read this.
We can all agree that for an array int[] A, where N = len(A), that there are N prefix sums.
prefix[0] = A[0], prefix[1] = A[0] + A[1], ... prefix[i] = A[0] + ... + A[i].

Then to calculate how many subarrays are divisible by K is logically equivalent to saying, how many ways can we pair up all prefix sum pairs (i,j) where i < j
such that (prefix[j] - prefix[i]) % K == 0.

Just from that information alone we easily get a O(n^2) solution.
Compute all prefix sums, then check all pair to see if k divides the difference between them.

However, if we just exploit some information w.r.t to the remainder of each prefix sum we can manipulate this into a linear algorithm. Here's how.

Number Theory Part
I noted above that we need to find all prefix sum pairs (i,j) such tha (p[j] - p[i]) % K == 0.
But this is only true, if and only if p[j] % K == p[i] % K
Why is this?

According the the division algorithm we can express p[j] and p[i] in the following way.
p[j] = bK + r0 where 0 <= r0 < K
p[i] = aK + r1 where 0<= r1 < K

Then p[j] - p[i] = (b*K + r0) - (a*K + r1)
= b*K - a*K + r0 - r1 = K*(b-a) + r0 - r1
Again: p[j] - p[i] = K*(b-a) + (r0-r1), in other words
K only divides p[j] - p[i] iff r0-r1 = 0 <-> r0 = r1 QED

But we should not forget about elements in the array that do not need a pairing, namely those that are are divisible by K. That's why I add mod[0] at the end.

Also counting pairs => N choose 2 = > n*(n-1) / 2
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*In c++ and java, a % K + K takes care of the cases where a < 0.
*/

/*
freq[0]=1 EXPLANATION
Consider this case. It's my first time meeting a remainder that equals zero. But wait, doesn't that mean that my subarray's sum is Divisible by K? If freq[0]!=1 then my counter wouldn't increment the first time I met a remainder=0. Therefore I need freq[0]=1 in order for my counter to consider the first subarray with a remainder that equals to zero.
*/

class Solution {
    public:
    int subarraysDivByK(vector<int>& A, int K) {
        // freq arrray init by 0
        vector<int> freq(K); //  number that I need to increment my counter with is the frequency of the remainder at its previous step.
        freq[0] = 1; 
        int prefix = 0, res = 0;
        for (int a : A) {
            prefix = (prefix + a % K + K) % K;
            res += freq[prefix]++;
        }
        return res;
    }
};
int main()
{
}