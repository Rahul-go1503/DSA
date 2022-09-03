#include <bits/stdc++.h>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    bool isSame(TreeNode* root1,TreeNode* root2){
        if(!root1&&!root2) return true;
        if((!root1&&root2)||(root1&&!root2)||(root1->val!=root2->val)) return false;
        bool left = isSame(root1->left,root2->right);
        bool right = isSame(root2->left,root1->right);
        return left&&right;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left,root->right);
    }
};