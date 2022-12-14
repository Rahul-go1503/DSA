#include <bits/stdc++.h>
using namespace std;
 
 struct Node
{
	int data;
	Node *left, *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
/*
 - BST to Max Heap
 - Given BST is CBT 
 - If min heap then use preorder traversal along with inorder(same as above)
*/
class Solution{
  public:
    void inorder(Node* root, vector<int> &a){
        if(!root) return;
        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);
    }
    int i = 0; // i ko global hi lena pdega no other option in max- heap
    Node* buildMaxHeap(Node* root,vector<int> &a){
        if(!root) return NULL;
        
        buildMaxHeap(root->left,a);
        buildMaxHeap(root->right,a);
        root->data = a[i++];
        
        return root;
    }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> arr;
        inorder(root,arr);
        buildMaxHeap(root,arr);
        
    }    
};