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


class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * successor(Node *root, Node *x, Node* par= NULL)
    {
        // no need to search node is given
        if(!root) return NULL;
        if(root->data<x->data){
            return successor(root->right,x,par);
        }
        if(root->data>x->data){
            return successor(root->left,x,root);
        }
        
        if(!root->right) return par;
        auto succ = root->right;
        while(succ->left) succ = succ->left;
        return succ;
    }
    Node * inOrderSuccessor(Node *root, Node *x){
        return successor(root,x);
    }
};

class Solution{
  public:
    Node * inOrderSuccessor(Node *root, Node *p)
    {
        if (root == NULL || p == NULL) return NULL;  
        Node *suc = NULL;
        while (root != NULL)
        {
            if (root->data <= p->data)
                root = root->right;
            else
            {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
};