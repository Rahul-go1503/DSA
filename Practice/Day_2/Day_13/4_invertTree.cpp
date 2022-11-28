/*********************************************************************************************

Question :


Notes :
Many might say why we need an iterative solution in every tree problem ?
The ans is simple, Tree can be skewed which effectively makes it a linked list.
And if we recurse in a large linked-list, the call stack will overflow for sure.
That's why its necessary to also know how to implement iteratively.
Honestly, iterative implementation also will utilize a stack, but it will be in heap.
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


TreeNode* invertTree(TreeNode* root) {
    if(!root) return NULL;
    TreeNode * temp= invertTree(root->left);
    root->left=invertTree(root->right);
    root->right=temp;
    return root;
}

TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* p = st.top();
        st.pop();
        if (p) {
            st.push(p->left);
            st.push(p->right);
            swap(p->left, p->right);
        }
    }
    return root;
}
int main()
{
}