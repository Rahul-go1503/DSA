#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// reverse inorder
class Solution {
    int sum = 0; // track max sum value
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        auto right = bstToGst(root->right);
        root->val += sum;
        sum = root->val;
        auto left = bstToGst(root->left);
        return root;
    }
};