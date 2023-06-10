/*********************************************************************************************

Question :


Notes :
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
    public:
    int select(int arr[], int i,int n)
    {
        int mn = i;
        for(int j = i+1;j<n;j++)
            if(arr[j]<arr[mn]) mn = j;
        return mn;
    }
     
    void selectionSort(int arr[], int n)
    {
       for(int i=0;i<n-1;i++){
           int j = select(arr,i,n);
           swap(arr[i],arr[j]);
       }
    }
};