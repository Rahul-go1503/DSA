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
    TreeNode* build(vector<int>& in, vector<int>& post,int &postStart, int s, int e){
        if(s>e) return NULL;
        
        int i = s;
        while(in[i]!=post[postStart]) i++;
        
        TreeNode* root = new TreeNode(in[i]);
        postStart--;
        root->right = build(in,post,postStart,i+1,e);
        root->left = build(in,post,postStart,s,i-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int e = in.size()-1;
        int postStart = e;
        return build(in,post,postStart,0,e);
    }
};