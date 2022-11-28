#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            while(q.size() && q.front()){
                Node* top = q.front();
                q.pop();
                Node* nxt = q.front();
                // if(!top) continue;
                top->next = nxt;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            q.pop();
            if(q.size()) q.push(NULL);
        }
        return root;
    }
};