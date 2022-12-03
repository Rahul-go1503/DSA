#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// always go for level order in these problems
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(!root) return {};
        
        vector<int> ans;
        int mn = INT_MAX, mx = INT_MIN;
        
        unordered_map<int,int> m;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        
        while(q.size()){
            int hd = q.front().first;
            Node* temp = q.front().second;
            q.pop();
            
            m[hd] = temp->data;
            if(temp->left) q.push({hd-1,temp->left});
            if(temp->right) q.push({hd+1,temp->right});
            
            if(hd<mn) mn = hd;
            if(hd>mx) mx = hd;
        }
        for(int i=mn;i<=mx;i++){
            ans.push_back(m[i]);
        }
        return ans;
    }
};

// https://www.geeksforgeeks.org/bottom-view-binary-tree/