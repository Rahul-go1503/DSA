/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O(M+N)
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int r= mat.size();
        int c = mat[0].size();
        int row=0;
        int col = c-1;
        while(row<r && col>=0){
            if(tar==mat[row][col]) return true;
            if(tar>mat[row][col]){
                row++;
            }else{
                col--;
            }
        }
        return false;
    }
};