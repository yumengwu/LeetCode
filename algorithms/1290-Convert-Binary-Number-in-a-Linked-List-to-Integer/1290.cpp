#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if (head == NULL) {
            return 0;
        }
        int res = 0;
        ListNode * cur = head;
        while (cur) {
            res = (res << 1) | cur->val;
            cur = cur->next;
        }
        return res;
    }
};