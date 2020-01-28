#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        TreeNode * node = new TreeNode(head->val);
        if (head->next == NULL) {
            return node;
        }
        ListNode * slow = head, * fast = head, * pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        node->val = slow->val;
        pre->next = NULL;
        node->left = sortedListToBST(head);
        if (slow->next) {
            node->right = sortedListToBST(slow->next);
        }
        return node;
    }
};