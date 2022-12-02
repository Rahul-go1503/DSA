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
    TreeNode* inOrder(TreeNode* root, bool &isBst, long &mx){
        if(!root) return NULL;
        
        TreeNode *left =NULL; //no need of right
        // TreeNode *left =NULL , *right = NULL;
        if(isBst) left = inOrder(root->left,isBst,mx);
        if(isBst ||root->val<=mx){
            isBst = false;
            return NULL;
        }
        mx = root->val;
        // if(isBst) right = inOrder(root->right,isBst,mx);
        inOrder(root->right,isBst,mx); // no need to check here
        return root;
        
    }
public:
    bool isValidBST(TreeNode* root) {
        bool isBst = true;
        long mx = LONG_MIN;
        inOrder(root,isBst,mx);
        return isBst;
    }
};
// mx value ki jgh prev node use kra ... is bst ki bhi need nhi rhi
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};