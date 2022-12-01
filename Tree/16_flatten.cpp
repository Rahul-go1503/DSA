#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// TC - O(), SC - O()
// not a good approach
class Solution {
    TreeNode* solve(TreeNode* root){
        if(!root) return NULL;
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        if(left){
            auto temp = root->right;
            root->right = root->left;
            left->right= temp;
            root->left = NULL;
        }
        
        while(root->right) root=root->right;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        solve(root);
    }
};

// ye dehne me chhota lg skta hai par khud se idea click kr easy nhi hai
// basically jis order me flatten krna hai uske reverse travarse kro means piche se suru hona hai
class Solution {
public:
    TreeNode *nxt = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = nxt;
        root->left = NULL;
        nxt = root;
    }
};