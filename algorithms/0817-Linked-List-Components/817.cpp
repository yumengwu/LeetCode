#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());
        int res = 0;
        while (head) {
            while (head && s.count(head->val) == 0) {
                head = head->next;
            }
            if (head) {
                ++res;
            }
            else {
                break;
            }
            while (head && head->next && s.count(head->next->val)) {
                head = head->next;
            }
            if (head) {
                head = head->next;
            }
        }
        return res;
    }
};

