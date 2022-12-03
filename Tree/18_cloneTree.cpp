#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;

    Node(int x){
        data= x;
        left = NULL;
        right = NULL;
        random = NULL;
    }
};
// here main problem is to clone the random pointer for that we hash the nodes to have a track which node is corresponding to which node
class Solution{
  public:
    Node* clone(Node* tree,unordered_map<Node*,Node*> &m){
      if(!tree) return NULL;
      
      Node* root = new Node(tree->data);
      m[tree]=root;
      root->left = clone(tree->left,m);
      root->right = clone(tree->right,m);
      return root;
  }
    void cloneRandom(Node* tree,Node* root,unordered_map<Node*,Node*> &m){
        if(!tree) return;
        if(tree->random) root->random = m[tree->random];
        else root->random = NULL;
        cloneRandom(tree->left,root->left,m);
        cloneRandom(tree->right,root->right,m);
    }
    /* The function should clone the passed tree and return 
       root of the cloned tree */
    Node* cloneTree(Node* tree)
    {
        unordered_map<Node*,Node*> m;
        Node* root = clone(tree,m);
        cloneRandom(tree,root,m);
        return root;
    }
};