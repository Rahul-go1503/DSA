#include<iostream>
using namespace std;
class Trie {
    Trie* child[26] = {};
    bool isLeaf = false;

public:
    void insert(string word) {
        int n = word.length();
        auto root = this;
        for(int i=0;i<n;i++){
            int idx = word[i] - 'a';
            if(!root->child[idx]) root->child[idx] = new Trie();
            root = root->child[idx];
        }
        root->isLeaf = true;
    }
    
    bool search(string word) {
        int n = word.length();
        auto root = this;
        for(int i=0;i<n;i++){
            int idx = word[i] - 'a';
            if(!root->child[idx]) return false;
            root = root->child[idx];
        }
        return root->isLeaf;
    }
    
    bool startsWith(string pre) {
        int n = pre.length();
        auto root = this;
        for(int i=0;i<n;i++){
            int idx = pre[i] -'a';
            if(!root->child[idx]) return false;
            root = root->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */