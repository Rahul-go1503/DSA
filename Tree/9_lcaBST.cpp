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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        // if both values smaller than go to left
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        // both greater than go to right
        }else if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        // if we have a split or one of the val is root itself return root
        return root;
    }
};
// iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root) {
        if(root->val > p->val && root->val > q->val){
            root= root->left;
        }else if(root->val < p->val && root->val < q->val){
            root= root->right;
        }else break;
    }
        return root;
    }
};