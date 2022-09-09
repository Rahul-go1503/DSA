#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O(N)
	Space Complexity: O(1)
*/

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0;
            vector<int> res;
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j] && A[i]==C[k]){
                    if(res.empty() || A[i]!=res.back())res.push_back(A[i]);
                    i++;j++;k++;
                }else if(A[i]<=B[j] && A[i]<=C[k]) i++;
                else if(B[j]<=A[i] && B[j]<=C[k]) j++;
                else k++;
            }
            return res;
        }

};
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0;
            vector<int> res;
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j] && A[i]==C[k]){
                    if(res.empty() || A[i]!=res.back())res.push_back(A[i]);
                    i++;j++;k++;
                }else if(A[i]<B[j]) i++;
                else if(B[j]<C[k]) j++;
                else k++;
            }
            return res;
        }

};