#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * slow = head, * fast = head, * pre;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        head = sortList(head);
        slow = sortList(slow);
        ListNode * nh = new ListNode(0);
        ListNode * cur = nh;
        while (head && slow) {
            if (head->val < slow->val) {
                cur->next = head;
                head = head->next;
            }
            else {
                cur->next = slow;
                slow = slow->next;
            }
            cur = cur->next;
            cur->next = NULL;
        }
        if (head) {
            cur->next = head;
        }
        else if (slow) {
            cur->next = slow;
        }
        return nh->next;
    }
};