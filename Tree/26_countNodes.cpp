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
// O(logN * logN)
class Solution {
    // return in terms of nodes
    int height(TreeNode* root){
        if(!root) return 0;
        // no need to cal for both subtree
        return 1 + max(height(root->left),height(root->right));
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        // count no of nodes including root node
        // lh if lh==rh and rh if lh==rh+1 means rh in both case
        // total nodes with level h is pow(2,h+1)-1; if level is 0,1,2...
        // here levels are 1,2,3... and 1 is added for root node
        int nodes = pow(2,rh),ln=0,rn=0;
        if(lh==rh){
            ln = countNodes(root->right);
        }else{
            rn = countNodes(root->left);
        }
        
        return nodes+ln+rn; // pne is always zero (ln or rn);
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;   
        int hl=0, hr=0;
        TreeNode *l=root, *r=root;

        // calculate left and right height
        while(l) {hl++;l=l->left;}
        while(r) {hr++;r=r->right;}

        // if same means complete tree in both sides
        if(hl==hr) return pow(2,hl)-1;
        // else
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};