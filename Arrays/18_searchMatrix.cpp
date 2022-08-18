/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O(RC)
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int r = mat.size();
        int c =mat[0].size();
        int s =0;
        int e= r*c-1;
        while(s<=e){
            int mid = (s+e)/2;
            int row = mid/c;
            int col = mid%c;
            if(tar==mat[row][col]) return true;
            else if( tar> mat[row][col]) s=mid+1;
            else e = mid-1;
        }
        return false;
    }
};