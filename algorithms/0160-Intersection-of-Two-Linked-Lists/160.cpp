#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        ListNode * curA = headA;
        ListNode * curB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; ++i) {
                curA = curA->next;
            }
        }
        else if (lenB > lenA) {
            for (int i = 0; i < lenB - lenA; ++i) {
                curB = curB->next;
            }
        }
        while (curA) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
    int getLength(ListNode * head) {
        if (head == NULL) {
            return 0;
        }
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};