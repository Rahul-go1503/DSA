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
// Not solved
TreeNode* BST(TreeNode* root,TreeNode* subRoot){
    if(!root) return NULL;
        if(root->val==subRoot->val) return root;
        else if(root->val>subRoot->val){
           return BST(root->left,subRoot);
        }else{
           return BST(root->right,subRoot);
        }
}
bool solve(TreeNode* root, TreeNode* subRoot){
    if(!root&&subRoot || root&&!subRoot) return false;
    if(!root&&!subRoot) return true;
    if(root->val!=subRoot->val) return false;
    bool left= solve(root->left,subRoot->left);
    if(!left) return false;
    bool right= solve(root->right,subRoot->right);
    if(!right) return false;
    return true;
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* node= BST(root,subRoot);
        return solve(node,subRoot);

}
int main()
{
}