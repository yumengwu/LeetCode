#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode * slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head, * fast = head;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
            }
        }
        return slow;
    }
};

