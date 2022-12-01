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

// code krne ke baad ho skta hai easy lge par yha tak krne me 1hr se bhi uper ka time lga hai mainly neg numbers or 2 node ke case ko deal krne me
class Solution {
    int solve(TreeNode*root, int& mx){
        if(!root) return -1001;
        int left = solve(root->left,mx);
        int right = solve(root->right,mx);
        
        if(left==-1001) left=0;
        if(right==-1001) right =0;
        
        int sum = root->val + max(left,right);
        
        // all possible ways for max
        // mx = max(max(root->val,root->val+left+right),max(sum,mx));
        mx = max(root->val+left+right,max(sum,mx));
        
        if(sum<0) return -1001;
        else return sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        int mx = -1001;
        solve(root,mx);
        return mx;
    }
};