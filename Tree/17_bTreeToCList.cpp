#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/
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

class Solution
{
  public:
    Node* head=NULL , *tail=NULL, *pre = NULL;
    Node* solve(Node* root){
        if(!root) return NULL;
        solve(root->right);
        if(tail==NULL) tail = root;
        root->right = pre;
        if(pre) pre->left = root;
        pre = root;
        solve(root->left);
        return pre;
    }
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        head = solve(root);
        tail->right = head;
        head->left = tail;
        return head;
    }
};