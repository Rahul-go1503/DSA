#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// TC - O(), SC - O()
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

Node* build(int *post ,int &node , int mn , int mx){
    if(node<0) return NULL;
    if(post[node]<mn || post[node]>mx) return NULL;
    
    Node* root = new Node(post[node]);
    node--;
    root->right = build(post,node,root->data,mx);
    root->left = build(post,node,mn,root->data);
    return root;
}

Node *constructTree (int post[], int size)
{
    int node = size-1;
    return build(post,node,INT_MIN,INT_MAX);
}