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
    //not solved
public:
    void solve(TreeNode* root,vector<string> &ans,string path){
        if(!root) return;
        if(!root->left&&!root->right){
            path+="->"+to_string(root->val);
            ans.push_back(path);
        }
        solve(root->left,ans,path);
        solve(root->right,ans,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root->val);
        solve(root,ans,path);
        return ans;
    }
};