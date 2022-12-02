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
 
// TC - O(N2), SC - O()
class Solution {
    TreeNode* build(vector<int>& pre, vector<int>& in,int &preStart, int s , int e){
        if(s>e) return NULL;
        int i = s;
        // search for root node in inorder
        while(in[i]!=pre[preStart]){
            i++;
        }
        TreeNode* root = new TreeNode(in[i]);
        
        // move to next node 
        //NODE SURELY PREORDER KE ORDER ME HI CREATE KRNEGE HONGE CHHAE LEFT OR RIGHT CHILD EXIST KRE YA NA KRE
        preStart++;
        
        root->left = build(pre,in,preStart,s,i-1);
        root->right = build(pre,in,preStart,i+1,e);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = in.size();
        int preStart = 0;
        return build(pre,in,preStart,0,n-1);
    }
};