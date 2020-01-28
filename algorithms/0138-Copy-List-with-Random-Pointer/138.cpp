#include "../header.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * nh = new Node(0, NULL, NULL);
        Node * nc = nh;
        Node * cur = head;
        unordered_map<Node *, Node *> m;
        while (cur) {
            Node * nn = new Node(cur->val, NULL, NULL);
            nc->next = nn;
            m[cur] = nn;
            nc = nc->next;
            cur = cur->next;
        }
        cur = head;
        nc = nh->next;
        while (cur) {
            nc->random = m[cur->random];
            cur = cur->next;
            nc = nc->next;
        }
        return nh->next;
    }
};