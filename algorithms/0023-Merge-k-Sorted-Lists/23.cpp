#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }
        while (n > 1) {
            int len = n / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwo(lists[i], lists[n - i - 1]);
            }
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                n = n / 2 + 1;
            }
        }
        return lists[0];
    }
    
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode* nn = new ListNode(0);
        ListNode* cur = nn;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        else if (l2) cur->next = l2;
        return nn->next;
    }
};
