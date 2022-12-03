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
// pura tree traverse krna hi pdega O(N)
 class Solution {
    void right(TreeNode* root,vector<int> &ans,int lv, int& mx){
        if(!root) return;
        if(mx<lv){
            mx = lv;
            ans.push_back(root->val);
        }
        right(root->right,ans,lv+1,mx);
        right(root->left,ans,lv+1,mx);
    }
public:
// no need of even mx, track by size of ans==mx if initial level is set to 1
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int mx = -1;
        right(root,ans,0,mx);
        return ans;
    }
};