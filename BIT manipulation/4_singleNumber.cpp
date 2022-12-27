#include <bits/stdc++.h>
using namespace std;
/*
every element appears twice except for one. Find that single one.
If we do "a^b" , it means that we are applying the XOR gate on the 2 numbers in a bitwise fashion ( on each of the corresponding bits of the numbers).
Similarly , if we observe ,

A^A=0
A^B^A=B
(A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int n : nums){
            ans^=n;
        }
        return ans;
    }
};