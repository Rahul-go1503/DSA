#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    void leftNodes(Node* root,vector<int> &ans){
        if(!root) return ; // ek bar hi condn true ho skti hai start me hi;
        
        // left nhi hai to hi right me ja rhe hai
        if(root->left){
            ans.push_back(root->data);
            leftNodes(root->left,ans);
        }else if(root->right){
            ans.push_back(root->data);
            leftNodes(root->right,ans);
            
        }
    }
    void leafNodes(Node*root,vector<int>&ans){
        if(!root) return;
        leafNodes(root->left,ans); // first left me gye then check kra
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        leafNodes(root->right,ans);
    }
    void rightNodes(Node*root,vector<int>&ans){
        if(!root) return;
        
        if(root->right){
            rightNodes(root->right,ans);
            ans.push_back(root->data);
        }else if(root->left){
            rightNodes(root->left,ans);
            ans.push_back(root->data);
        }
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->data);
        leftNodes(root->left,ans);
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
        rightNodes(root->right,ans);
        return ans;
    }
};