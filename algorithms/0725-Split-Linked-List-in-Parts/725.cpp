#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        if (root == NULL) {
            for (int i = 0; i < k; ++i) {
                res.push_back(NULL);
            }
            return res;
        }
        if (k == 1) {
            res.push_back(root);
            return res;
        }
        int len = getLen(root);
        int remain = len;
        ListNode * cur = root;
        int K = k;
        while (remain) {
            int curLen = remain / K + (remain % K == 0 ? 0 : 1);
            --K;
            remain -= curLen;
            ListNode * t = cur;
            while (--curLen) {
                t = t->next;
            }
            res.push_back(cur);
            cur = t->next;
            t->next = NULL;
        }
        while (res.size() < k) {
            res.push_back(NULL);
        }
        return res;
    }
    
    int getLen(ListNode * node) {
        return node == NULL ? 0 : getLen(node->next) + 1;
    }
};

int main()
{
    return 0;
}