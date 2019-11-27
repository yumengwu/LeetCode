#include "../header.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        queue<ListNode *> q1, q2;
        ListNode *cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                q1.push(cur);
            }
            else
            {
                q2.push(cur);
            }
            cur = cur->next;
        }
        ListNode *nh = new ListNode(-1);
        cur = nh;
        while (q1.size() > 0)
        {
            cur->next = q1.front();
            cur = cur->next;
            q1.pop();
        }
        while (q2.size() > 0)
        {
            cur->next = q2.front();
            cur = cur->next;
            q2.pop();
        }
        cur->next = NULL;
        return nh->next;
    }
};