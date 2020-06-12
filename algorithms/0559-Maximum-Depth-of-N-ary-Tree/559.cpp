#include "../header.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < root->children.size(); ++i) {
            res = max(res, maxDepth(root->children[i]));
        }
        return res + 1;
    }
};

