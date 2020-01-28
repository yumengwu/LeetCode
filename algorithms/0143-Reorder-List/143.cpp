#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        stack<ListNode *> s;
        ListNode * cur = head, * t;
        int len = 0;
        while (cur) {
            ++len;
            s.push(cur);
            cur = cur->next;
        }
        cur = head;
        while (len > 0) {
            cout<<len<<endl;
            t = s.top();
            s.pop();
            t->next = cur->next;
            cur->next = t;
            cur = cur->next;
            --len;
            if (len > 0) {
                --len;
                cur = cur->next;
            }
            else {
                cur->next = NULL;
            }
        }
        cur->next = NULL;
    }
};

int main()
{
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    s.reorderList(head);
    return 0;
}