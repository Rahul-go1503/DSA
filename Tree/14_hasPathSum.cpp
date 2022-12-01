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
 
// TC - O(), SC - O()
class Solution {
public:
    bool hasPathSum(TreeNode* root, int tar) {
        if(!root) return false;
        if(root->val==tar && !root->left && !root->right) return true;
        bool left = hasPathSum(root->left,tar-root->val);
        if(left) return true;
        bool right = hasPathSum(root->right,tar-root->val);
        if(right) return true;
        return false;
    }
};