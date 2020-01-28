#include "../header.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        root->next = NULL;
        if (root->left == NULL && root->right == NULL) {
            return root;
        }
        queue<Node *> q;
        q.push(root);
        for (;;) {
            vector<Node *> v(q.size());
            int index = 0;
            while (q.size() > 0) {
                Node * node = q.front();
                q.pop();
                v[index++] = node;
            }
            for (int i = 0; i < v.size() - 1; ++i) {
                v[i]->next = v[i + 1];
            }
            v.back()->next = NULL;
            if (v[0]->left) {
                for (int i = 0; i < v.size(); ++i) {
                    q.push(v[i]->left);
                    q.push(v[i]->right);
                }
            }
            else {
                break;
            }
        }
        return root;
    }
};

int main()
{
    return 0;
}