#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode * n1 = head;
        ListNode * n2 = head;
        while (n2 && n2->next) {
            n1 = n1->next;
            n2 = n2->next->next;
            if (n1 == n2) {
                break;
            }
        }
        if (n2 == NULL || n2->next == NULL) {
            return NULL;
        }
        n1 = head;
        while (n1 != n2) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n2;
    }
};