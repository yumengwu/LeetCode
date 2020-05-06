#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* nn = new ListNode(0);
        nn->next = head;
        ListNode* cur = nn;
        while (cur->next && cur->next->next) {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = cur->next->next;
            cur->next->next = temp;
            cur = cur->next->next;
        }
        return nn->next;
    }
};
