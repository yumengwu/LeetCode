#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * nh = new ListNode(0);
        ListNode * cur = nh;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
                cur->next = NULL;
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
                cur->next = NULL;
            }
        }
        if (l1) {
            cur->next = l1;
        }
        else if (l2) {
            cur->next = l2;
        }
        return nh->next;
    }
};