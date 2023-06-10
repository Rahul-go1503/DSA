#include<bits/stdc++.h>
using namespace std;

/*Complete the function below
Node is as follows:
*/
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Return True if the given Binary Tree is a Full Binary Tree. Else return False
bool isFullTree (struct Node* root)
{
    // if(!root) return true;

    // dono nhi hai to true or dono hai to check for subtree
    if(!root->left && !root->right) return true;
    if(root->left && root->right){
        bool left = isFullTree(root->left);
        bool right = isFullTree(root->right);
        return left && right;
    }
    else return false;
}