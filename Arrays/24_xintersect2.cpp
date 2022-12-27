#include <bits/stdc++.h>
using namespace std;

/*
 Each element in the result must appear as many times as it shows in both arrays
Methods - 
- store one nums and iterate second one
- sort then two ponters 
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
- use two pointer approach - N,1;

What if nums1's size is small compared to nums2's size? Which algorithm is better?
- sort num1 and search binarly or go for 1st approach

What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at
once?
- If nums1 fits into the memory, we can use Approach 1 which stores all elements of nums1 in the HashMap. Then, we can sequentially load and process nums2.
If neither nums1 nor nums2 fits into the memory, we split the numeric range into numeric sub-ranges that fit into the memory.
We modify Approach 1 to count only elements which belong to the given numeric sub-range.
We process each numeric sub-ranges one by one, util we process all numeric sub-ranges.
For example:
Input constraint:
1 <= nums1.length, nums2.length <= 10^10.
0 <= nums1[i], nums2[i] < 10^5
Our memory can store up to 1000 elements.
Then we split numeric range into numeric sub-ranges [0...999], [1000...1999], ..., [99000...99999], then call Approach 1 to process 100 numeric sub-ranges. 
*/


/* O(N*M),O(1)
Accepted since Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    for (auto n : nums2) {
        auto itr=find(nums1.begin(),nums1.end(),n);
        if(itr!=nums1.end()){
            ans.push_back(n);
            nums1.erase(itr);
        }
    }
    return ans;
}