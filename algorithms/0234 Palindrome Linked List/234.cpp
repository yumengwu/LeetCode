#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode * slow = head, * fast = head, * pre;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        slow = reverseList(slow);
        pre = head;
        while (pre) {
            if (pre->val != slow->val) {
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return slow == NULL || slow->next == NULL;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * nh = new ListNode(-1);
        nh->next = head;
        ListNode * cur = head;
        while (cur && cur->next) {
            ListNode * temp = cur->next;
            cur->next = temp->next;
            temp->next = nh->next;
            nh->next = temp;
        }
        return nh->next;
    }
};