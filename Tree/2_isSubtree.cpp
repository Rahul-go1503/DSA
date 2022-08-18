/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    bool solve(TreeNode* root, TreeNode* subRoot){
        // if(root->val!=subRoot->val) return false;
        if(!root&&!subRoot) return true;
        if(root&&!subRoot || !root&&subRoot || root->val!=subRoot->val) return false;
        // cout<<"root: "<<root->val<<" subRoot: "<<subRoot->val<<endl;
        return solve(root->left,subRoot->left)&&solve(root->right,subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        bool temp=false;
        if(root->val==subRoot->val){
            temp= solve(root,subRoot);
        }if(root->val!=subRoot->val||!temp){
            bool left = isSubtree(root->left,subRoot);
            if(left) return true;
            bool right = isSubtree(root->right,subRoot);
            if(right) return true;
        }
        return temp;
    }
};
//same but easy to understand
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(!s) return false;
        if (isSame(s,t)) return true;
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
        
    }
    bool isSame(TreeNode *s, TreeNode *t)
    {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        
        return isSame(s->left, t->left) && isSame(s->right, t->right);
        
    }
};
int main(){
    TreeNode t;

}