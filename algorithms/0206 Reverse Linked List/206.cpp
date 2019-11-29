#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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

int main()
{
    ListNode * h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    Solution s;
    h = s.reverseList(h);
    while (h) {
        cout<<(h->val)<<endl;
        h = h->next;
    }
    return 0;
}