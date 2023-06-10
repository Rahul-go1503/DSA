#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

struct Node {
    int index, freq;
    Node *left, *right;
    Node(int i, int f){
        index = i, freq = f;
        left = right = NULL;
    }
};
struct cmpr {
    bool operator()(Node *f, Node* s){
        return f->freq > s->freq;
    }
};
Node* buildHuffmanTree(vector<int> &arr){
    int n = arr.size();
    priority_queue<Node*,vector<Node*>,cmpr> pq;
    for(int i=0;i<n;i++) pq.push(new Node(i,arr[i]));

    while(pq.size()>1){
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node * root = new Node(-1,left->freq + right->freq);
        pq.push(root);
        root->left = left;
        root->right = right;
    }
    return pq.top();
}
void assignCodes(Node* root, string code, vector<string> &res){
    if(!root) return;
    if(root->index !=-1){
        res[root->index] = code;
        return;
    }
    assignCodes(root->left,code+"0",res);
    assignCodes(root->right,code+"1",res);
}
vector<string> huffmanCode(vector<int> &arr)
{
    int n = arr.size();
    if(n==1) return {"0"};
    Node * root = buildHuffmanTree(arr);
    vector<string> res(n);
    assignCodes(root,"",res);
    return res;
}