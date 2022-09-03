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
//     Day -10
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while (root)
            {
            s.push(root);
            ans.push_back(root->val);
            root=root->left;   
            }
            root = s.top();
            s.pop();
            root=root->right;
        }
        return ans;
    }
int main(){

}