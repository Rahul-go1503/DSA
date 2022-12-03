#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to return a list containing elements of left view of the binary tree.
void left(Node* root,int lv, vector<int>& ans,unordered_set<int> &s){
    if(!root) return;
    if(!s.count(lv)){
        ans.push_back(root->data);
        s.insert(lv);
    }
    left(root->left,lv+1,ans,s);
    left(root->right,lv+1,ans,s);
}

// no need of set we can track just max level
vector<int> leftView(Node *root)
{
   vector<int> ans;
   unordered_set<int> s;
   left(root,0,ans,s);
   return ans;
}
