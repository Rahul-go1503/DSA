/*********************************************************************************************

Question :


Notes :
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
    return;
}
void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        int j=i+1;
        while(j<n){
            if(arr[j]<arr[minIndex]) minIndex=j;
            j++;
        }
        swap(arr[i],arr[minIndex]);
    }
    return;
}