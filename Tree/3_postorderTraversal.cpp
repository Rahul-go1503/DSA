#include <bits/stdc++.h>
using namespace std;

// Day 10

//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// Day_10
class Solution {
    void solve(TreeNode* root , vector<int> &ans){
        if(!root) return ;
        solve(root->left,ans);
        solve(root->right,ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while (root){
                s.push(root);
                root=root->left;  
            }

            root = s.top();

            if(!root->right){
                ans.push_back(root->val);
                s.pop();
                root = s.top();
                ans.push_back(root->val);
                s.pop();
            }else{
                root = s.top();
                root=root->right;
            }
 
            if(root && !root->left && !root->right){
                ans.push_back(root->val);
            }else{
                root = s.top();
                ans.push_back(root->val);
            }
        }
        return ans;
    }