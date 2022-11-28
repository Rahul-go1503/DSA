#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
    int solve(Node* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        
        int lt = solve(root->left);
        if(lt==-1) return -1;
        
        int rt = solve(root->right);
        if(rt==-1) return -1;
        
        return lt+rt==root->data ? lt+rt+root->data : -1;
    }
    public:
    bool isSumTree(Node* root)
    {
        if(!root) return true;
        return solve(root)==-1? false:true; 
    }
};