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

class Solution{   
    bool solve(vector<int> &arr,int n,int i,int sum, int tar){
        if(sum==tar){
            return true;
        }
        for(int k=i;k<n && sum<tar;k++){
            sum+=arr[k];
            bool temp = solve(arr,n,k+1,sum,tar);
            if(temp) return true;
            sum-=arr[k];
        }
        return false;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        return solve(arr,n,0,0,sum);
    }
};
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<bool> prev(sum+1,false);
        vector<bool> curr(sum+1,false);
        for(int i=0;i<n;i++){
            for(int j=1;j<=sum;j++){
            if(arr[i]>j){
                curr[j]=prev[j];
                continue;
            }else{
                curr[j] = prev[j] || prev[j-arr[i]];
            }
            prev= curr; 
        }
        }
        return prev[sum];
    }
};