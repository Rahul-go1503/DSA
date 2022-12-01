/*********************************************************************************************

Question :


Notes :
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* buildTree(int s,int e,vector<int>&nums){
        if(s>e) return NULL;
        int mid = s +(e-s)/2;
        auto root = new TreeNode(nums[mid]);
        root->left = buildTree(s,mid-1,nums);
        root->right = buildTree(mid+1,e,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s=0;
        int e=nums.size();
        return buildTree(s,e,nums);
    }
};