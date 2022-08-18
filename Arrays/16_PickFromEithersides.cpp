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

int solve(vector<int> &A, int B) {
    int n= A.size();
    int sum=0;
    int mx =INT_MIN;
    for(int i=0;i<B;i++){
        sum+=A[i];
    }
    for(int i=0;i<B;i++){
        sum-=A[B-i-1];
        sum+=A[n-i-1];
        if(sum> mx) mx=sum;
    }
    return mx;
}
