#include "../header.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

/*
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        helper(head);
        return head;
    }
    
    Node * helper(Node * node) {
        Node * nh = new Node();
        nh->next = node;
        node->prev = nh;
        Node * cur = nh;
        while (cur->next) {
            if (cur->next->child) {
                Node * nc = helper(cur->next->child);
                nc->next = cur->next->next;
                if (nc->next) {
                    nc->next->prev = nc;
                }
                cur->next->next = cur->next->child;
                cur->next->child->prev = cur->next;
                cur->next->child = NULL;
                cur = nc;
            }
            else {
                cur = cur->next;
            }
        }
        node->prev = NULL;
        return cur;
    }
};*/

class Solution {
public:
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }
    
    Node* helper(Node* node) {
        if (!node) {
            return NULL;
        }
        Node* last;
        while (node) {
            last = node;
            if (node->child) {
                Node* nn = helper(node->child);
                nn->next = node->next;
                if (node->next) {
                    node->next->prev = nn;
                }
                node->next = node->child;
                node->next->prev = node;
                node->child = NULL;
                node = nn->next;
                last = nn;
            }
            else {
                node = node->next;
            }
        }
        last->next = NULL;
        return last;
    }
};

