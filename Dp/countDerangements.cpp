/*********************************************************************************************

Question : House Robber II


Notes :
~~ Self Thought 
agar recursion me do function call ho rhe hai n-1 & n-2 to base case me condition check kro
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
long long int solveRec(int n){
    //if(n<=1) return 0; // base case thinking wrong
    if(n==1) return 0;
    if(n==2) return 1;
    return (n-1)*(solveRec(n-1)+solveRec(n-2));
}
// Tabulation direct ~~ space
# define mod 1000000007
long long int countDerangements(int n) {
    if(n==1) return 0;
    long long int prev2 = 0;
    long long int prev1 = 1;
    for(int i=3;i<=n;i++){
        long long int curr = ((i-1)*(((prev2%mod) + (prev1%mod))%mod))%mod;
        //long long int curr = (i-1)*(prev2+prev1);
        prev2=prev1;
        prev1 = curr;
    }
    return prev1;
}