#include <bits/stdc++.h>
using namespace std;

/*
- Hard taged
- Methods 
 - Brute - n2,1
 - using 2 array - n,n
 - using 1 array - n,n
 - single pass - n,1 --> best one
 - your soln - nlogn, n -> not even mention in official soln :(
 - single pass but even more readable and consise 
*/

// nlogn, n + n
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>> order;
        for(int i=0;i<n;i++) order.push_back({ratings[i],i});

        sort(order.begin(),order.end()); // order in ascending order of ratings

        int cndy = 0;
        vector<int> candy(n);
        for(int i =0;i<n;i++){
            int idx = order[i][1];
            int RC = order[i][0];
            int RL = idx == 0 ? INT_MAX : ratings[idx-1];    
            int RR = idx == n-1 ? INT_MAX : ratings[idx+1];

            if(RC > RL && RC > RR)
                candy[idx] = max(candy[idx-1],candy[idx+1]) + 1;
            else if(RC > RL)
                candy[idx] = candy[idx-1] + 1;
            else if(RC > RR)
                candy[idx] = candy[idx+1] + 1;
            else candy[idx] = 1;
            cndy +=  candy[idx];
        }
        return cndy;
    }
};

class Solution {
    int count(int n) {
        return (n * (n + 1)) / 2;
    }
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) {
            return ratings.size();
        }
        int candies = 0;
        int up = 0;
        int down = 0;
        int oldSlope = 0;
        for (int i = 1; i < ratings.size(); i++) {
            // calculating new slope
            int newSlope = (ratings[i] > ratings[i - 1]) ? 1 
                : (ratings[i] < ratings[i - 1] ? -1 
                : 0);

            // locating mountain
            if ((oldSlope > 0 && newSlope == 0) || (oldSlope < 0 && newSlope >= 0)) {
                candies += count(up) + count(down) + max(up, down);
                up = 0;
                down = 0;
            }
            // valley ko next calculation me count kr rhe hai
            if (newSlope > 0) {
                up++;
            } else if (newSlope < 0) {
                down++;
            } else {
                candies++;
            }

            oldSlope = newSlope;
        }
        candies += count(up) + count(down) + max(up, down) + 1;
        return candies;
    }
};



class Solution {
public:
    int candy(vector<int>& ratings) {
        // see the graph and whenever a lower point hit or flat line is hit, give them the lower value
        int ans=1;
        int up=0,down=0,peak=0;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                // there is / thus up++ and peak is new up, eg. (1,2,3,4,,..)
                peak = ++up;
                // whatever is current value add that and add 1 more because up was 0 from start and first point is already included in answer
                ans += up+1;
                // down is 0 now since \ is not there in count now
                down = 0;
            }
            else if(ratings[i]==ratings[i-1]){
                // there is flat - now your up =0 and down also 0, cause no maxima minima slopes
                up=down=peak=0;
                // include the candies here, these should be 1 we assume if it were to be more we 
                // will change that in upcoming iterations
                ans +=1;
            }
            else{
                
                // increase down slope
                down++;
                // no up now
                up=0;
                
                // more we go downhill with \ (add the number of consecutive downhills)
                // now => ans +=  down; because
                // like (1,2,3,4 : 3,2,1) is same as (1,2,3,4 : 1,2,3)
                ans +=  down;

                // we may need to increase peak because for case (1,2,3,4,3,2,1) 
                // if we get new \ (dip), answer should be (1,2,3,4,5,4,3,2,1)
                // we already did (1,2,3,4,1,2,3,4) but we need to do
                // (1,2,3,4,5: 1,2,3,4), thus just increase the peak by 1 in case we go down more than peak (down>peak)
                ans += (down>peak);
            }
        }
        return ans;
    }
};