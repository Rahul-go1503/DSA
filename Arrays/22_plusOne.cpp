/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        int i = n-1;
        while(i>=0){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            // if 9 make it 0
            digits[i--]=0;
        }
        // 00000
        // means we have to add 1 in begining
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};


vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    vector<int> ans;
    int s=0;
    while(A[s]==0){
        s++;
    }
    if(A[n-1]<9){
        int i=n-1;
        ans.push_back(++A[i--]);
        while(i>=s) ans.push_back(A[i--]);
    }else{
        int i=n-1;
        while(i>=s&&A[i]==9){
            ans.push_back(0);
            i--;
        }
        if(i<s) ans.push_back(1);
        else ans.push_back(++A[i--]);
        while(i>=s) ans.push_back(A[i--]);
    }
    reverse(ans.begin(),ans.end());    
    return ans;
     
}

vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    int i = n-1;
    while(A[i] == 9 and i>=0)
    {  
        A[i] = 0;
        i--;
    }
    if(i<0)
    {
        A.insert(A.begin(),1);
        return A;
    }
    A[i]++;
    while(A[0]==0) A.erase(A.begin());
    return A;
}

