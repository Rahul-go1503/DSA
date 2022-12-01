#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :
find the sum of the product of each node and its mirror image 
**********************************************************************************************/

// TC - O(), SC - O()
#define mod 1000000007
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
long long mul(int a,int b){
    return (a%mod*b%mod)%mod;
}
long long add(long long a, long long b){
    return (a%mod + b%mod)%mod;
}
class Solution
{
    void solve(Node* node1, Node* node2, long long &ans){
        ans=add(ans,mul(node1->data,node2->data));
        if(node1->left && node2->right){
            solve(node1->left, node2->right,ans);
        }
        if(node1->right && node2->left){
            solve(node1->right,node2->left,ans);
        }
    }
    public:
    long long imgMultiply(Node *root)
    {
        long long ans=0;
        ans+= mul(root->data,root->data);
        if(!root->left || !root->right) return ans;
        solve(root->left,root->right,ans);
        return ans;
    }
};