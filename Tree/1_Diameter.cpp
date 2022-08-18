/*********************************************************************************************

Question :


Notes :
The question can be solved by small modification to program of Height of tree.
The idea is quite simple. Max value of Height(leftSubtree)+Height(rightSubtree) (at any node ) is the diameter. Keep track of maxium diameter duing traversal and find the height of the tree.

d=max(d,ld+rd); => This line maintains the max diameter.

here counting edge in diameter and nodes in height.

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
int solve(TreeNode *root, int &d)
{
    if (!root)return 0;
    int lh = solve(root->left, d);
    int rh = solve(root->right, d);
    d = max(d, lh + rh);
    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    int d = 0;
    solve(root, d);
    return d;
}

int main()
{
}