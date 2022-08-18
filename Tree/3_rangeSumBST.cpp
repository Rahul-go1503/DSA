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
// binary tree 
class Solution {
public:
    void solve(TreeNode* root, int low, int high,long long int &ans){
        if(!root) return;
        if(root->val>=low&&root->val<=high){
            ans+=root->val;
        }
        solve(root->left,low,high,ans);
        solve(root->right,low,high,ans);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        long long int ans=0;
        solve(root,low,high,ans);
        return ans;
    }
};
//binary search tree 
class Solution {
public:
    void solve(TreeNode* root, int low, int high,long long int &ans){
        if(!root) return;
        if(root->val>=low&&root->val<=high){
            ans+=root->val;
            solve(root->left,low,high,ans);
            solve(root->right,low,high,ans);
        }
        if(root->val>high)
            solve(root->left,low,high,ans);
        else
            solve(root->right,low,high,ans);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        long long int ans=0;
        solve(root,low,high,ans);
        return ans;
    }
};
//short ~~ archit91
//✔️ Solution - I (Simple DFS)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        if(!root) return 0;
        return  (root -> val >= L && root -> val <= H ? root -> val : 0) +  // add root's value if it lies within [L, H]
                rangeSumBST(root -> left, L, H) +   // recurse left
                rangeSumBST(root -> right, L, H);   // recurse right
    }
};
//✔️ Solution - II (BST Optimized DFS)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        if(!root) return 0;
        int ans = root -> val >= L && root -> val <= H ? root -> val : 0;
        if(root -> val > L) ans += rangeSumBST(root -> left, L, H);
        if(root -> val < H) ans += rangeSumBST(root -> right, L, H);
        return ans;
    }
};
//✔️ Solution - III (BST Optimized BFS)
class Solution {
public:
    int rangeSumBST(TreeNode* T, int L, int H) {
        queue<TreeNode*> q;
        q.push(T);
        int sum = 0, v;
        while(!q.empty()) {
            T = q.front(); q.pop();
            v = T -> val;
            if(v >= L and v <= H)   sum += v;
            if(v > L && T -> left)  q.push(T -> left);
            if(v < H && T -> right) q.push(T -> right);
        }
        return sum;
    }
};
//✔️ Solution - IV (Morris Traversal)
// https://leetcode.com/problems/range-sum-of-bst/discuss/1628229/C%2B%2BPython-Simple-Solution-w-Explanation-or-DFS-%2B-BFS-w-Optimizations-%2B-O(1)-Morris