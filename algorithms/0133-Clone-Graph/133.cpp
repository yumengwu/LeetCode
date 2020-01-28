#include "../header.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return node;
        }
        map<Node *, Node *> m;
        queue<Node *> q;
        Node * nn = new Node();
        nn->val = node->val;
        m[node] = nn;
        q.push(node);
        set<Node *> s;
        s.insert(node);
        while (q.size()) {
            Node * top = q.front();
            q.pop();
            for (int i = 0; i < top->neighbors.size(); ++i) {
                if (m.find(top->neighbors[i]) != m.end()) {
                    m[top]->neighbors.push_back(m[top->neighbors[i]]);
                }
                else {
                    Node * temp = new Node();
                    temp->val = top->neighbors[i]->val;
                    m[top->neighbors[i]] = temp;
                    m[top]->neighbors.push_back(temp);
                }
                if (s.find(top->neighbors[i]) == s.end()) {
                    s.insert(top->neighbors[i]);
                    q.push(top->neighbors[i]);
                }
            }
        }
        return nn;
    }
};