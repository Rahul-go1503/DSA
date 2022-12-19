#include <bits/stdc++.h>
using namespace std;

/*
In a given cartesian plane, there are N points. We need to find the Number of Pairs of  points(A, B) such that

Point A and Point B do not coincide.
Manhattan Distance and the Euclidean Distance between the points should be equal.

- they will be equal iff 2*|x2-x1|*|y2-y1| == 0 => x1==x2 || y1==y2
- same point repeat hua to use ignore nhi krna hai kyuki vo baki points ke sath pairing kr skta hai.
- but jab bakio ke saath pair count krenge to same points ke sath bhi counting count ho jaegi 
- ek baar x ke same milne ke kaarn and 2nd time y ke same milne ke kaarn.
*/
class Solution {
  public:
    int numOfPairs(int x[], int y[], int n) {
        unordered_map<int,int> mp1, mp2;
        map<pair<int,int>,int> mp3;

        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += mp1[x[i]]++; // prev me same x jitni baar mila utne pair bn jaenge
            cnt += mp2[y[i]]++; // ,, ,, ,,
            cnt -= 2*mp3[{x[i],y[i]}]++; // if we have same points in input then then we have two minus two times(read above)
        }
        return cnt;
    }
};