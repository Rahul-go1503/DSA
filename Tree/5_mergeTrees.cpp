/*********************************************************************************************

Question :


Notes :
The question can be solved by small modification to program of Height of tree.
The idea is quite simple. Max value of Height(leftSubtree)+Height(rightSubtree) (at any node ) is the diameter. Keep track of maxium diameter duing traversal and find the height of the tree.

d=max(d,ld+rd); => This line maintains the max diameter.
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
    TreeNode* solve(TreeNode* root1, TreeNode* root2){
        if(!root1) return root2;
        if(!root2) return root1;
        root1->val+=root2->val;
        root1->left=solve(root1->left,root2->left);
        root1->right=solve(root1->right,root2->right);
        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};