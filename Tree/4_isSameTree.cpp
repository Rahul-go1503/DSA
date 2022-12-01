#include <bits/stdc++.h>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


// two trees are same or not
// subproblem of subtree wali problem
class Solution {
public:
//     DAY -10
    bool isSameTree(TreeNode* p, TreeNode* q) {
      // if(!p || !q) return p==q;
      if(!p&&!q) return true;
      if((p && !q) || (q && !p) || (p->val!=q->val) ) return false;
      bool left=isSameTree(p->left,q->left);
      bool right=isSameTree(p->right,q->right);
      return left&&right;
        
    }
};

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
// more efficient
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(!r1 && !r2) return true;
        if((r1&&!r2) || (r2&&!r1)) return false;
        
        return r1->data==r2->data && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
};