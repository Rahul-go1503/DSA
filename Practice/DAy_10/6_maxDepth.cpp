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
public:
    //Day-10
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        int left= maxDepth(root->left);
        int right=maxDepth(root->right);
        return max(left,right)+1;
        
    }
};