/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
// not solved
 void setZeroes(vector<vector<int>>& matrix) {     
        int rowsize=matrix.size(); 
        int columnsize=matrix[0].size(); 
        vector<int>rowmarker(rowsize,1);
        vector<int>columnmarker(columnsize,1); 
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++)
            {
                if(matrix[i][j]==0)
                {
                    rowmarker[i]=0; 
                    columnmarker[j]=0;
                }
            }
        } 
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++)
            {
                if(rowmarker[i]==0 or columnmarker[j]==0)
                    matrix[i][j]=0;
             }
        }
        
    }
void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
}
int main()
{
}