#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        vector<int> temp;
        dfs(res, temp, root);
        return res;
    }
    
    void dfs(int& res, vector<int>& temp, TreeNode* node) {
        if (!node) {
            return;
        }
        temp.push_back(node->val);
        if (!(node->left || node->right)) {
            if (check(temp)) {
                ++res;
            }
            temp.pop_back();
            return;
        }
        if (node->left) {
            dfs(res, temp, node->left);
        }
        if (node->right) {
            dfs(res, temp, node->right);
        }
        temp.pop_back();
    }
    
    bool check(vector<int>& temp) {
        map<int, int> m;
        for (int i : temp) {
            ++m[i];
        }
        int cntodd = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second & 1) {
                ++cntodd;
            }
        }
        if (temp.size() & 1 == 0) {
            return cntodd == 0;
        }
        else {
            return cntodd == 0 || cntodd == 1;
        }
    }
};

