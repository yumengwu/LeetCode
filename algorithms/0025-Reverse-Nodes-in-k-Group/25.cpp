#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode * h = new ListNode(-1);
        h->next = head;
        ListNode * cur = h;
        ListNode * last = h;
        while (cur && cur->next) {
            // cout<<cur->val<<endl;
            ListNode * ch = cur;
            cur = cur->next;
            bool hasK = true;
            ListNode * t = ch;
            for (int i = 0; i < k; ++i) {
                if (t->next == NULL) {
                    hasK = false;
                    break;
                }
                t = t->next;
            }
            if (!hasK) {
                break;
            }
            for (int i = 0; i < k - 1; ++i) {
                // cout<<cur->val<<' ';
                if (cur->next == NULL) {
                    break;
                }
                ListNode * temp = cur->next;
                cur->next = temp->next;
                temp->next = ch->next;
                ch->next = temp;
            }
        }
        return h->next;
    }
};

int main()
{
    Solution s;
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = s.reverseKGroup(head, 3);
    for (int i = 0; i < 5; ++i) {
        cout<<head->val<<' ';
        head = head->next;
    }cout<<endl;
    return 0;
}