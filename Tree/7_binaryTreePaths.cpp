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

class Solution {
    //have to check whether right or wrong
public:
    void solve(TreeNode* root,vector<string> &ans,string path){
        path+="->"+to_string(root->val);
        if(!root->left&&!root->right){
            ans.push_back(path);
        }
        if(root->left) solve(root->left,ans,path);
        if(root->right) solve(root->right,ans,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root->val);
        if(root->left) solve(root->left,ans,path);
        if(root->right) solve(root->right,ans,path);
        return ans;
    }
};