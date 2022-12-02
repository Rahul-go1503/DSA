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
 
// you are required to complete this function

// no need
struct Node* findKey(struct Node* root,int key){
    if(!root) return NULL;
    if(root->data==key) return root;
    auto left = findKey(root->left,key);
    if(left) return left;
    auto right = findKey(root->right,key);
    if(right) return right;
    return NULL;
}

// level order travarsal to find key and end node
// track par node of end node
struct Node* par = NULL;
struct Node* findBottomRightMostNode(struct Node* root , struct Node* &keyNode, int key){
    queue<Node*> q;
    q.push(root);
    Node* temp = NULL;
    while(q.size()){
        temp = q.front();
        q.pop();
        if(temp->data== key) keyNode = temp; 
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        if(temp->left || temp->right) par = temp;
    }
    return temp;
}
struct Node* deletionBT(struct Node* root, int key)
{
    if(!root) return root;
    if(!root->left &&!root->right){
        if(root->data==key) return NULL;
        else return root;
    }
    // auto keyNode = findKey(root,key);
    Node* keyNode = NULL;
    auto rightmostNode = findBottomRightMostNode(root,keyNode,key);
    if(keyNode){
        swap(rightmostNode->data,keyNode->data);
        if(par->left==rightmostNode){
            par->left=NULL;
        }else par->right=NULL;
        delete rightmostNode;
    }
    return root;
}