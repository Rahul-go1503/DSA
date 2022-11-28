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
//     DAY -10
    bool isSameTree(TreeNode* p, TreeNode* q) {
      // if(!p || !q) return p==q;
      if(!p&&!q) return true;
      if((p && !q) || (q && !p) || (p->val!=q->val) ) return false;
      bool left=isSameTree(p->left,q->left);
      bool right=isSameTree(p->right,q->right);
      return left&&right;
        
    }
};