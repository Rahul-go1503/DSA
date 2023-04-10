/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in 
circle in a fixed direction

adjust :
 0 --> k
 1 --> k + 1
 2 --> k + 2
 3 --> k + 3
*/
class Solution
{
    public:
    int josephus(int n, int k)
    {
        // 1 - based indexing first -1 and then adjust then again add 1;
       return n == 1 ? 1 : (josephus(n-1,k) - 1 + k)%n + 1;
    }
};