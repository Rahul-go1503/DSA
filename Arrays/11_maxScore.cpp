/*********************************************************************************************

Question :
1423. Maximum Points You Can Obtain from Cards

Notes :
Key idea: You can’t choose 2nd element from the beginning unless you have chosen the first one. Similarly, you can’t choose 2nd element from last unless you have chosen the last one.

So now just try all possible combinations. Choose 0 from the beginning and K from the last, 1 from front and K-1 from last and so on until K from beginning and 0 from behind. Maximum out of all those combinations is the answer.
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &cp ,int i, int j, int k){
        if(k==0) return 0;
        int first = cp[i] + solve(cp,i+1,j,k-1);
        int second = cp[j] + solve(cp,i,j-1,k-1);
        return max(first,second);
    }
public:
    int maxScore(vector<int>& cp, int k) {
        int i=0;
        int j=cp.size()-1;
        return solve(cp,i,j,k);
    }
};

    int maxScore2(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        
        vector<int> cummulativeSumFromFront(n+1, 0);
        vector<int> cummulativeSumFromBehind(n+1, 0);
        
        sum = 0;
        for (int i=0; i<n; i++) {
            sum += cardPoints[i];
            cummulativeSumFromFront[i+1] = sum;
        }
        sum = 0;
        for (int i=n-1; i>=0; i--) {
            sum += cardPoints[i];
            cummulativeSumFromBehind[i] = sum;
        }
        
        // Reversing is optional. I reversed it so that it would be easy
        // to access sum of last (k-i) elements by just indexing at [k-i]
        // Otherwise, I would have had to index it at [n-k+i] which would
        // have made it difficult to read.
        reverse(cummulativeSumFromBehind.begin(), cummulativeSumFromBehind.end());
        
        int answer = 0;
        for(int i=0; i<=k; i++) {      
            answer = max(answer, 
                           cummulativeSumFromFront[i] // Sum of first 'i' cards.
                         + cummulativeSumFromBehind[k-i]); // Sum of last 'k-i' cards.
        }
        return answer;
    }

int maxScore(int arr[], int k) {
    int n = sizeof(arr)/sizeof(int);
    
    int sum = 0;
    for(int i=0; i<k; i++){
        sum+=arr[i];
    }
    int mx = sum; 
    for(int i=0; i<k; i++){
        sum = sum - arr[k-i-1] + arr[n-i-1];
        mx = max(mx, sum);
    }
    return mx;
}
int main()
{
}