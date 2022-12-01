#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :
find the sum of the product of each node and its mirror image 
**********************************************************************************************/

// TC - O(), SC - O()
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
    int getTotalSum(TreeNode *root){
        if(!root) return 0;
        return root->val+ getTotalSum(root->left) + getTotalSum(root->right);
    }
    int spilt(TreeNode* node,int &sum, long long &mx){
        if(!node) return 0;
        int temp = node->val + spilt(node->left,sum,mx) + spilt(node->right,sum,mx); // sum upto that node
        mx = max(mx,temp*1LL*(sum-temp));
        return temp;
    }
public:
    int maxProduct(TreeNode* root) {
        int sum = getTotalSum(root);
        long long mx = 1;
        spilt(root,sum,mx);
        return mx%1000000007;
    }
};