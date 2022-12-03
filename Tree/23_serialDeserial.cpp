#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// TC - O(), SC - O()
class Codec {
public:
    void serial(TreeNode* root, string &data){
        if(!root){
            data+="N ";
            return;
        }
        data+=to_string(root->val)+" ";
        serial(root->left,data);
        serial(root->right,data);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        serial(root,data);
        return data;
    }

    TreeNode* deserial(string data,int &s){
        int e = data.find(" ",s);
        string sub = data.substr(s,e-s);
        s = e+1;
        if(sub=="N") return NULL;
        
        TreeNode* root = new TreeNode(stoi(sub));
        if(s<data.length()) root->left = deserial(data,s);
        if(s<data.length()) root->right = deserial(data,s);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int s = 0;
        return deserial(data,s);
    }
};

class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
