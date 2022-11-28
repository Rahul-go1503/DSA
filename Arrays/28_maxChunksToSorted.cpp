#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int mx = arr[0];
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>mx) mx = arr[i];
            if(i==mx) cnt++;
        }
        return cnt;
    }
};