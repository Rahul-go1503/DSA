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
/*
For a complete binary tree,
there should not be any node after we met an empty one.
*/

// BFS, DFS height based
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool isNull = false;

        q.push(root);
        while(q.size()){
            auto node = q.front();
            q.pop();

            if(!node) isNull = true;
            else{
                // kya phele null mil chuka hai
                if(isNull) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

// have a look
int target_height = 0, last_level_filled = false;
bool isCompleteTree(TreeNode* r, int h = 0) {
  if (r == nullptr) {
    if (target_height == 0) {
        target_height = h;
    } else if (h == target_height - 1) {
        last_level_filled = true;
    }
    return h == target_height - last_level_filled;
  }
  return isCompleteTree(r->left, h + 1) && isCompleteTree(r->right, h + 1);
}