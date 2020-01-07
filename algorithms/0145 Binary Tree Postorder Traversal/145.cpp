#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        set<TreeNode *> st;
        stack<TreeNode *> sk;
        sk.push(root);
        while (sk.size()) {
            TreeNode * top = sk.top();
            if ((top->left == NULL || st.find(top->left) != st.end()) && (top->right == NULL || st.find(top->right) != st.end())) {
                res.push_back(top->val);
                st.insert(top);
                sk.pop();
            }
            else {
                if (top->right != NULL && st.find(top->right) == st.end()) {
                    sk.push(top->right);
                }
                if (top->left != NULL && st.find(top->left) == st.end()) {
                    sk.push(top->left);
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}