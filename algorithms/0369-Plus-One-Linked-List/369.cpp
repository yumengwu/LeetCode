#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        int c = helper(head);
        if (c == 0) {
            return head;
        }
        else {
            ListNode * nh = new ListNode(1);
            nh->next = head;
            return nh;
        }
    }
    int helper(ListNode * node) {
        if (node->next == NULL) {
            ++node->val;
            if (node->val >= 10) {
                node->val -= 10;
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            int c = helper(node->next);
            if (c) {
                ++node->val;
                if (node->val >= 10) {
                    node->val -= 10;
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
    }
};