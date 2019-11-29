#include "../header.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        queue<Node *> q;
        q.push(root);
        while (q.size() > 0) {
            vector<Node *> v(q.size());
            for (int i = 0; i < v.size(); ++i) {
                v[i] = q.front();
                q.pop();
                if (i > 0) {
                    v[i - 1]->next = v[i];
                }
            }
            v.back()->next = NULL;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i]->left) {
                    q.push(v[i]->left);
                }
                if (v[i]->right) {
                    q.push(v[i]->right);
                }
            }
        }
        return root;
    }
};