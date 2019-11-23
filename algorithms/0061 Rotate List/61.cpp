#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        ListNode * cur = head;
        int len = 0;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        k = len - k - 1;
        cur = head;
        while (k-- > 0) {
            cur = cur->next;
        }
        ListNode * e = cur;
        while (e->next) {
            e = e->next;
        }
        e->next = head;
        e = cur->next;
        cur->next = NULL;
        return e;
    }
};