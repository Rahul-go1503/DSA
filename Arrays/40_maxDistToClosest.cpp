#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int n = s.size();
        vector<int> left(n,0),right(n,0);
        int pos = -2*n;
        for(int i=0;i<n;i++){
            if(s[i]==1) pos = i;
            else left[i] = pos;
        }
        pos = 2*n;
        for(int i=n-1;i>=0;i--){
            if(s[i]==1) pos = i;
            else right[i] = pos;
        }

        int mx = -1;
        for(int i=0;i<n;i++){
            if(s[i]==0){
                mx = max(mx,min(i-left[i],right[i]-i));
            }
        }
        return mx;
    }
};

    int maxDistToClosest(vector<int>&seats) {
        int left = -1;
        int maxDistance = 0;
        int n = seats.size();
        for(int right = 0; right < n ; right++) {
            if(seats[right] == 1) {
                if(left == -1) {
                    //handles edge case when it leads with 0. 
                    maxDistance = right;
                } else {
                    //when your seat is inbetween 1s, you need to find half point between the two so you divide by 2
                    maxDistance = max(maxDistance, (right- left) /2); 
                }
                
                left = right;
            }
        }
        if (seats[n-1] == 0) {
            //handles edge case when ends with 0.
            maxDistance = max(maxDistance, (n-1-left)); 
        }
        return maxDistance;
    }