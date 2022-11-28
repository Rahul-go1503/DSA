#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/


 // DP + HASHING ~~ HARD Ques

// TC - O(N3), SC - O(1) -- Accepted
class Solution{ 
public:
    int lengthOfLongestAP(int a[], int n) {
        int mx = 1;
        for(int i =0 ;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int c = 2;
                int d = a[j]-a[i];
                for(int k = j+1;k<n;k++){
                    if(a[k]==a[i]+c*d){
                        c++;
                    }
                }
                mx = max(mx,c);
            }
        }
        return mx;
    }
};

// GFGs - O(N2),O(N2) , sorted array if
int lenghtOfLongestAP(int set[], int n)
{
    if (n <= 2)  return n;
 
    // Create a table and initialize all values as 2. The value of
    // L[i][j] stores LLAP with set[i] and set[j] as first two
    // elements of AP. Only valid entries are the entries where j>i
    int L[n][n];
    int llap = 2;  // Initialize the result
 
    // Fill entries in last column as 2. There will always be
    // two elements in AP with last number of set as second
    // element in AP
    for (int i = 0; i < n; i++)
        L[i][n-1] = 2;
 
    // Consider every element as second element of AP
    for (int j=n-2; j>=1; j--)
    {
        // Search for i and k for j
        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1)
        {
           if (set[i] + set[k] < 2*set[j])
               k++;
 
           // Before changing i, set L[i][j] as 2
           else if (set[i] + set[k] > 2*set[j])
           {   L[i][j] = 2, i--;   }
 
           else
           {
               // Found i and k for j, LLAP with i and j as first two
               // elements is equal to LLAP with j and k as first two
               // elements plus 1. L[j][k] must have been filled
               // before as we run the loop from right side
               L[i][j] = L[j][k] + 1;
 
               // Update overall LLAP, if needed
               llap = max(llap, L[i][j]);
 
               // Change i and k to fill more L[i][j] values for
               // current j
               i--; k++;
           }
        }
 
        // If the loop was stopped due to k becoming more than
        // n-1, set the remaining entities in column j as 2
        while (i >= 0)
        {
            L[i][j] = 2;
            i--;
        }
    }
    return llap;
}

// dp[index][diff] equals to the length of arithmetic sequence at index with difference diff.
// C++, using unordered_map
// TLE now.

    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int res = 2, n = A.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)  {
                int d = A[j] - A[i];
                dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;
                res = max(res, dp[d][j]);
            }
        return res;
    }
// C++, using vector

    int longestArithSeqLength(vector<int>& A) {
        int res = 2, n = A.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)  {
                int d = A[j] - A[i] + 1000;
                dp[j][d] = max(2, dp[i][d] + 1);
                res = max(res, dp[j][d]);
            }
        return res;
    }