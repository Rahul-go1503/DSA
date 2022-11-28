#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// N,N
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        // hd, values
        unordered_map<int,vector<int>> m;
        // hd, node
        queue<pair<int,Node*>> q;
        q.push({0,root});
        
        // by mn , mx we achieve o(n) soln
        int mn = 0, mx = 0;

        // level order se hi uper se niche shi print hoga
        while(q.size()){
            int hd = q.front().first;
            Node* node = q.front().second;
            q.pop();
            m[hd].push_back(node->data);
            if(node->left) q.push({hd-1,node->left});
            if(node->right) q.push({hd+1,node->right});
            
            if(mn>hd) mn = hd;
            if(mx<hd) mx = hd;
        }
        
        vector<int> ans;
        for(int i =mn;i<=mx;i++){
            for(auto &v : m[i]){
                ans.push_back(v);
            }
        }
        return ans;
    }
};