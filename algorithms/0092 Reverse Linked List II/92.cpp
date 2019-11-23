#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m == n) {
            return head;
        }
        ListNode * first = new ListNode(-1);
        first->next = head;
        ListNode * cur = first;
        int index = m - 1;
        while (index > 0) {
            cur = cur->next;
            --index;
        }
        stack<ListNode *> s;
        ListNode * temp = cur;
        for (int i = 0; i < n - m + 1; ++i) {
            temp = temp->next;
            s.push(temp);
        }
        temp = temp->next;
        while (s.size()) {
            ListNode * node = s.top();
            s.pop();
            cur->next = node;
            cur = cur->next;
        }
        cur->next = temp;
        return first->next;
    }
};