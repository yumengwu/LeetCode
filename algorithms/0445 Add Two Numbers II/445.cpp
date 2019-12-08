#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode * cur = l1;
        while (cur) {
            ++len1;
            cur = cur->next;
        }
        cur = l2;
        while (cur) {
            ++len2;
            cur = cur->next;
        }
        ListNode * nh = helper(l1, len1, l2, len2);
        if (nh->val >= 10) {
            ListNode * temp = new ListNode(nh->val / 10);
            nh->val %= 10;
            temp->next = nh;
            nh = temp;
        }
        return nh;
    }
    ListNode * helper(ListNode * l1, int len1, ListNode * l2, int len2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (len1 == len2) {
            ListNode * node = helper(l1->next, len1 - 1, l2->next, len2 - 1);
            if (node == NULL) {
                node = new ListNode(l1->val + l2->val);
                return node;
            }
            else {
                ListNode * nn = new ListNode(node->val / 10);
                nn->val += l1->val + l2->val;
                node->val %= 10;
                nn->next = node;
                return nn;
            }
        }
        else {
            if (len1 > len2) {
                ListNode * node = helper(l1->next, len1 - 1, l2, len2);
                ListNode * nn = new ListNode(node->val / 10);
                nn->val += l1->val;
                node->val %= 10;
                nn->next = node;
                return nn;
            }
            else {
                ListNode * node = helper(l1, len1, l2->next, len2 - 1);
                ListNode * nn = new ListNode(node->val / 10);
                nn->val += l2->val;
                node->val %= 10;
                nn->next = node;
                return nn;
            }
        }
    }
};

int main()
{
    return 0;
}