#include <bits/stdc++.h>
using namespace std;


/*
Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Note: The extra space is only for the array to be returned.
Try and perform all operations within the provided array. 
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= N <= 105
0 <= A[i] <= N-1, for each valid i
*/
class Solution{
  public:
    vector<int> duplicates(int nums[], int n) {
        vector<int> res;
        for(int i=0;i<n;i++){
            int idx = nums[i];
            if(nums[i]==i || nums[i] == -1 || nums[idx]==-1) continue;
            if(nums[idx] == nums[i]){
                // res.push_back(nums[i]);
                nums[idx] = -1;
            }else{
                swap(nums[i--],nums[idx]);
            }
        }
        vector<int> em = {-1};
        for(int i=0;i<n;i++) if(nums[i] == -1) res.push_back(i);
        return res.size() ? res : em;
    }
};

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // First check all the values that are
        // present in an array then go to that
        // values as indexes and increment by
        // the size of array
        for (int i = 0; i < n; i++) {
            int index = arr[i] % n;
            arr[index] += n;
        }
    
        // Now check which value exists more
        // than once by dividing with the size
        // of array
        bool flag = false;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((arr[i] / n) > 1) {
                ans.push_back(i);
                flag = true;
            }
        }
        if (!flag) ans.push_back(-1);
        return ans;
    }
};
