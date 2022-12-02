#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/
struct Node
{
	int data;
	Node* left, *right;
};
// Function to delete a node from BST.
Node *deleteNode(Node *root, int x) {
    if(!root) return root;
    // if x is smaller delete in left subtree(sub problem) it will return root of that subtree
    // after deletion, then we will assign that root to left of main root
    if(root->data > x){
        root->left = deleteNode(root->left,x);
        return root;
    }
    
    if(root->data < x){
        root->right = deleteNode(root->right,x);
        return root;
    }
    
    //root->data == x
    
    // Case-1 it is leaf node delete it return null
    if(!root->left && !root->right){
        delete root;
        return NULL;
    }
    
    // Case-2 left no exist, simply delete and return right subtree
    if(!root->left){
        Node* temp = root->right;
        delete root;
        return temp;
    }
    // Case-3 right....
    if(!root->right){
        Node* temp = root->left;
        delete root;
        return temp;
    }
    // Case-4 both ..., swap with next greater value or min value in right subtree
    Node * succPar = root;
    Node* succ = root->right;
    
    while(succ->left){
        succPar = succ;
        succ = succ->left;
    }
    
    // if succ's left doesn't exist(ek bhi nhi mila)
    if(succPar==root){
        succPar->right = succ->right;
    }
    
    else{
        succPar->left = succ->right;
    }
    
    root->data = succ->data;
    delete succ;
    return root;
}