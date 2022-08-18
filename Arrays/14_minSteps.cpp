/*********************************************************************************************

Question :
You are in an infinite 2D grid where you can move in any of the 8 directions

 (x,y) to 
    (x-1, y-1), 
    (x-1, y)  , 
    (x-1, y+1), 
    (x  , y-1),
    (x  , y+1), 
    (x+1, y-1), 
    (x+1, y)  , 
    (x+1, y+1) 
You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.

NOTE: This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.

Notes :

**********************************************************************************************/

/*
	Time Complexity: O(N)
	Space Complexity: O(1)

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int ans =0;
    for(int i=1;i<n;i++) ans+= max(abs(A[i]-A[i-1]),abs(B[i]-B[i-1]));
    return ans;
}
