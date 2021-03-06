#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode * head = new ListNode(0);
//         ListNode * cur = head;
//         int carry = 0;
//         while (l1 || l2 || carry) {
//             int temp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
//             ListNode * n = new ListNode(temp >= 10 ? temp - 10 : temp);
//             cur->next = n;
//             cur = cur->next;
//             carry = temp >= 10 ? 1 : 0;
//             if (l1) l1 = l1->next;
//             if (l2) l2 = l2->next;
//         }
//         return head->next;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0);
        ListNode * cur = head;
        int c = 0;
        while (l1 || l2 || c) {
            int temp = c;
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(temp % 10);
            cur = cur->next;
            c = temp / 10;
        }
        return head->next;
    }
};