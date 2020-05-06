#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nn = new ListNode(0);
        nn->next = head;
        ListNode* fast = nn, * slow = nn;
        while (n) {
            --n;
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return nn->next;
    }
};

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int len = getlength(head);
//         if (len == 0) {
//             return NULL;
//         }
//         if (n > len) {
//             return head;
//         }
//         if (len == n) {
//             return head->next;
//         }
//         ListNode * cur = head, * temp;
//         for (int i = 0; i < len - n - 1; ++i) {
//             cur = cur->next;
//         }
//         temp = cur->next;
//         cur->next = cur->next->next;
//         delete temp;
//         return head;
//     }
    
//     int getlength(ListNode * node) {
//         return node ? 1 + getlength(node->next) : 0;
//     }
// };