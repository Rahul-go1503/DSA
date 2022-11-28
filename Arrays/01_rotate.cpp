/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()
*/


#include <bits/stdc++.h>
using namespace std;

// one rotation , O(N),O(1);
void rotate(int arr[], int n)
{
    int temp = arr[n-1];
    for(int i=n-1;i>0;i--) arr[i]=arr[i-1];
    arr[0]= temp;
    
}