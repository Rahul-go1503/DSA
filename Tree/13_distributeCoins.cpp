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
class Solution {
    int solve(TreeNode* root, int &m){
        if(!root) return 0;
        int left = solve(root->left,m); // get req coins from left side
        int right = solve(root->right,m); // ,, ,, ,, ,, right side
        
        int val = left + right + root->val; // rem coins in that node
        m+=abs(left) + abs(right); // moves upto that node
        return val-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        solve(root,moves);
        return moves;
    }
};