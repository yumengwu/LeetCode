#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        ListNode * odd = new ListNode(0);
        ListNode * even = new ListNode(0);
        ListNode * ocur = odd;
        ListNode * ecur = even;
        ListNode * cur = head;
        while (cur) {
            ocur->next = cur;
            cur = cur->next;
            ocur = ocur->next;
            ocur->next = NULL;
            if (cur) {
                ecur->next = cur;
                cur = cur->next;
                ecur = ecur->next;
                ecur->next = NULL;
            }
        }
        ocur->next = even->next;
        return odd->next;
    }
};