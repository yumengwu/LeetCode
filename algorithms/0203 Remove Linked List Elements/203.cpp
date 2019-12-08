#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        ListNode * nh = new ListNode(0);
        nh->next = head;
        ListNode * ncur = nh, * cur = head;
        while (cur) {
            if (cur->val == val) {
                ListNode * temp = cur;
                cur = cur->next;
                ncur->next = cur;
                delete temp;
            }
            else {
                ncur = ncur->next;
                cur = cur->next;
            }
        }
        return nh->next;
    }
};