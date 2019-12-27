#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        vector<string> sv;
        preorder(root, sv);
        string res = sv[0];
        for (int i = 1; i < sv.size(); ++i) {
            res += ",";
            res += sv[i];
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = split(data);
        if (v.size() == 0) {
            return NULL;
        }
        TreeNode * root = new TreeNode(0);
        dehelper(v, 0, root);
        return root;
    }
    
private:
    void preorder(TreeNode * node, vector<string> & res) {
        if (node == NULL) {
            res.push_back("n");
            return;
        }
        res.push_back(to_string(node->val));
        preorder(node->left, res);
        preorder(node->right, res);
    }
    
    vector<string> split(string s) {
        vector<string> v;
        string temp = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ',') {
                v.push_back(temp);
                temp = "";
            }
            else {
                temp += s[i];
            }
        }
        if (temp.length()) {
            v.push_back(temp);
        }
        return v;
    }
    
    int dehelper(vector<string> & v, int index, TreeNode * node) {
        if (index >= v.size()) {
            return index;
        }
        node->val = stoi(v[index]);
        if (v[index + 1] == "n" && v[index + 2] == "n") {
            node->left = NULL;
            node->right = NULL;
            return index + 3;
        }
        else if (v[index + 1] == "n") {
            node->left = NULL;
            node->right = new TreeNode(0);
            return dehelper(v, index + 2, node->right);
        }
        else {
            node->left = new TreeNode(0);
            int next = dehelper(v, index + 1, node->left);
            if (v[next] != "n") {
                node->right = new TreeNode(0);
                return dehelper(v, next, node->right);
            }
            else {
                node->right = NULL;
                return next + 1;
            }
        }
    }
};

int main()
{
    Codec c;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    c.deserialize(c.serialize(root));
    return 0;
}