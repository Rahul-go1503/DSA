#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()


#include <bits/stdc++.h> 
int solveFir(vector<int>& arr, int s, int e,int tar){
    while(s<e){
        int mid =s +(e-s)/2;
        if(tar<=arr[mid]){
            e = mid;
        }else s = mid+1;
    }
    return arr[s]==tar? s:-1;
}
int solveSec(vector<int>& arr, int s, int e,int tar){
    while(s<e){
        int mid =s +(1+e-s)/2; // look here
        if(tar<arr[mid]){
            e = mid-1;
        }else s = mid;
    }
    return arr[s]==tar?s:-1;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> occ;
    return occ = {solveFir(arr,0,n-1,k),solveSec(arr,0,n-1,k)};
}