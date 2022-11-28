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
void solve(TreeNode* root,vector<string> &ans,string path){
        if(!root->left&&!root->right){
            ans.push_back(path);
            return;
        }
        if(root->left){
        solve(root->left,ans,path+"->"+to_string(root->left->val));
        }
        if(root->right){
        solve(root->right,ans,path+"->"+to_string(root->right->val));
        }
}
vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path=""+to_string(root->val);
        solve(root,ans,path);
        return ans;
    }
int main()
{
}