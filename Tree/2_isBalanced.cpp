/*********************************************************************************************

Question :


Notes :

This problem is generally believed to have two solutions: the top down approach and the bottom up way.

2.The second method is based on DFS. Instead of calling depth() explicitly for each child node, we return the height of the current node in DFS recursion. When the sub tree of the current node (inclusive) is balanced, the function dfsHeight() returns a non-negative value as the height. Otherwise -1 is returned. According to the leftHeight and rightHeight of the two children, the parent node could check if the sub tree
is balanced, and decides its return value.



Another way of proving the time complexity of first approach is O(nlogn) using Master Theory:

Time complexity for depth:

T(n) = 2T(n/2) + O(1)

a = 2, b =2, d = 0

a > b^d, therefore, O(n^(logba)) = O(n)

Time complexity for isBalanced:

T(n) = 2T(n/2) + O(n)

a = 2, b =2, d = 1

a = b^d, therefore, O(n^d*logn) = O(nlogn)
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
pair<bool,int> isBalanceFast(TreeNode * root){
        if(!root){
            return make_pair(1,0);
        }
        pair<bool,int> left = isBalanceFast(root->left);
        pair<bool,int> right = isBalanceFast(root->right);

        pair<bool,int> ans;
        bool diff = abs(left.second-right.second)<=1;
        ans.first= left.first&&right.first&&diff;
        ans.second= max(left.second,right.second)+1;
        return ans;
}
bool isBalanced(TreeNode* root) {
        return isBalanceFast(root).first;
}


// 2nd solution DFS
int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }

 // Day 12