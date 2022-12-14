#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
	int data;
	Node *left, *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
/*
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
isCBT - 2*i + 1and node count methods
*/
// BFS
class Solution {
  public:
    bool isHeap(struct Node* tree) {
        queue<Node*> q;
        q.push(tree);
        
        bool isNull = false;
        
        while(q.size()){
            auto node = q.front();
            q.pop();
            
            if(!node) isNull = true;
            else{
                if(isNull) return false;
                if(node->left && node->right && (node->data < node->left->data || node->data < node->right->data))
                    return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};