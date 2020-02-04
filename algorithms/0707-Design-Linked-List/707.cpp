#include "../header.h"

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode();
        head->next = head;
        head->prev = head;
        length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= length) {
            return -1;
        }
        ListNode * cur = head->next;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode * node = new ListNode();
        node->val = val;
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        ++length;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode * node = new ListNode();
        node->val = val;
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
        ++length;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length || index < 0) {
            return;
        }
        ListNode * cur = head, * node;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        node = new ListNode();
        node->val = val;
        node->next = cur->next;
        node->prev = cur;
        cur->next->prev = node;
        cur->next = node;
        ++length;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) {
            return;
        }
        ListNode * cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        ListNode * temp = cur->next;
        cur->next = temp->next;
        temp->next->prev = cur;
        // delete temp;
        --length;
    }
    
private:
    struct ListNode {
        int val;
        ListNode * next;
        ListNode * prev;
    };
    
    ListNode * head;
    int length;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    return 0;
}