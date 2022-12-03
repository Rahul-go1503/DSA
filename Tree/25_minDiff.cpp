#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

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
// TC - O(), SC - O()
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	bool solve(Node* root,int k, int &mn){
	    if(!root) return 0;
	    if(root->data==k){
	        mn = 0;
	        return 1;
	    }
	    
	    if(root->data>k){
	        mn = min(mn,root->data-k);
	        if(solve(root->left,k,mn)) return 1;
	    }else{
	        mn = min(mn,k-root->data);
	        if(solve(root->right,k,mn)) return 1;
	    }
	}
    int minDiff(Node *root, int k)
    {
        int mn = INT_MAX;
        solve(root,k,mn);
        return mn;
    }
};