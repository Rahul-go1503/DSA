/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int clr=0;
        while(i<n&&clr<n){
            if(nums[i]==0){
                i++;
                clr++;
            }
            else if(nums[clr]){clr++;}
            else{
                swap(nums[i++],nums[clr++]);
            }
        }
        clr=i;
        while(i<n&&clr<n){
            if(nums[i]==1){
                i++;
                clr++;
            }
            else if(nums[clr]==2){clr++;}
            else{
                swap(nums[i++],nums[clr++]);
            }
        }
        return;
    }
void sortColors(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    int i = 0;
    while (i <= end) {
        if (nums[i] == 0) {
            nums[i]=1;
            nums[start]=0;
            start++;
            i++;
        } else if (nums[i] == 2) {
            nums[i]=nums[end];
            nums[end]=2;
            end--;
        } else {
            i++;
        }
    }
}
void sortColors(int A[], int n) {
        int i = 0, j = n-1;
        // i = zero se ek aage rhega, j = 2 se ek piche rhega
        // k dekhega ki zero hai to i se swap kr do or 2 hai to j se or ek hai to aage bd jao
        for(int k=0; k<=j; )
        {
        	if(A[k]==0)  swap(A[i++], A[k++]);
        	else if(A[k]==2)  swap(A[j--], A[k]);
        	else k++;
        }        
    }









// two pass O(m+n) space
void sortColors(int A[], int n) {
    int num0 = 0, num1 = 0, num2 = 0;
    
    for(int i = 0; i < n; i++) {
        if (A[i] == 0) ++num0;
        else if (A[i] == 1) ++num1;
        else if (A[i] == 2) ++num2;
    }
    
    for(int i = 0; i < num0; ++i) A[i] = 0;
    for(int i = 0; i < num1; ++i) A[num0+i] = 1;
    for(int i = 0; i < num2; ++i) A[num0+num1+i] = 2;
}

// one pass in place solution
void sortColors(int A[], int n) {
    int n0 = -1, n1 = -1, n2 = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) 
        {
            A[++n2] = 2; A[++n1] = 1; A[++n0] = 0;
        }
        else if (A[i] == 1) 
        {
            A[++n2] = 2; A[++n1] = 1;
        }
        else if (A[i] == 2) 
        {
            A[++n2] = 2;
        }
    }
}

// one pass in place solution
// MY Fav
void sortColors(int A[], int n) {
    int i = 0, k = n - 1;
    for (int j = 0; j <= k; ++j){
        if (A[j] == 0 && j != i)
            swap(A[j--], A[i++]);
        else if (A[j] == 2 && j != k)
            swap(A[j--], A[k--]);
    }
}