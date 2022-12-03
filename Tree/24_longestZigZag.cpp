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
class Solution {
    void solve(TreeNode* root,int &mx,int cnt,bool left = true){
        if(!root) return;
        // inorder traversal kr rha hu
        // agar root hai to count 1 se bdega hi
        cnt++;
        // count change hote hi max ke liye check kra
        mx = max(mx,cnt);

        // go either left or right
        if(left) solve(root->left,mx,cnt,false);
        else solve(root->right,mx,cnt,true);
        
        // restart calu phele se oposite
        // yha cnt 0 se suru hoga kyuki ek node to hai hi
        if(!left) solve(root->left,mx,0,false);
        else solve(root->right,mx,0,true);
    }
public:
    int longestZigZag(TreeNode* root) {
        int mx = 0;
        solve(root,mx,-1);
        return mx;
    }
};