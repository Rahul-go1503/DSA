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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            vector<int> temp;
            while(q.size() && q.front()){
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
            q.pop();
            if(q.size()) q.push(NULL);
        }
        // just reversing the ans for 2 varient
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// recursive ~ DFS
void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
    if (!node) return;
    if (level >= ans.size())
        ans.push_back({});
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level+1);
    levelOrder(ans,node->right,level+1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    levelOrder(ans,root,0);
    reverse(ans.begin(),ans.end());
    return ans;
}
// bottom - up
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            // vector<int> temp;
            while(q.front()){
                auto node = q.front();
                q.pop();
                s.push(node);
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            s.push(NULL);
            q.pop();
            if(q.size()) q.push(NULL);
        }
        s.pop();
        while(s.size()){
            vector<int> temp;
            while(s.size() && s.top()){
                auto node = s.top();
                s.pop();
                temp.push_back(node->val);
            }
            if(s.size()) s.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};