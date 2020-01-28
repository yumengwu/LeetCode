#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * pre = new ListNode(-1);
        pre->next = head;
        ListNode * curr = head;
        ListNode * res = pre;
        while (curr && curr->next) {
            if (curr->val != curr->next->val) {
                curr = curr->next;
                pre = pre->next;
            }
            else {
                int val = curr->val;
                while (curr && curr->val == val) {
                    curr = curr->next;
                } 
                pre->next = curr;
            }
        }
        return res->next;
    }
};

int main()
{
    return 0;
}