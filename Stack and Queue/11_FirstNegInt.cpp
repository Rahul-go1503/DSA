#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :
 stores only useful elements of the current window of k elements. An element is useful if it is in the current window and it is a negative integer.
**********************************************************************************************/

// TC - O(N), SC - O(N)
vector<long long> printFirstNegativeInteger(long long A[],long long N, long long K) {
    queue<long long> q;
    vector<long long> ans(N-K+1);
    int i =0,k=0;
    for(;i<K;i++) if(A[i]<0) q.push(i);
    for(;i<N;i++){
        ans[k++] = q.size()>0 ? A[q.front()] : 0;
        if(q.size() && q.front()<(i-K+1)) q.pop();
        if(A[i]<0) q.push(i);
    }
    ans[k] = q.size()>0 ? A[q.front()] : 0;
    return ans;
 }
 // two pointer approach
// O(N),O(1) fni - first negative integer
 vector<int> firstNegative(vector <int> arr, int n, int k) {
    vector<int> ans(n - k + 1);
    int idx = 0,fni = 0;
    // Traversing for every window's end.
    for (int e = k - 1; e < n; e++) {
        while (fni<e && (fni <= e-k || arr[fni] >= 0)) fni++;
        // If we found a negative.
        ans[idx++] = arr[fni]<0 ? arr[fni] : 0;
    }
    return ans;
}
