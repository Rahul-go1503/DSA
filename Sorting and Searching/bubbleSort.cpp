/*********************************************************************************************

Question :


Notes :
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=1;i<n;i++){
        bool isSwapped = false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwapped= true;
            }
        }
        if(!isSwapped) break;
    }
}
