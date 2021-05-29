/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* newhead;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextnode = curr->next;
            curr->next = newhead;
            if (curr == head) curr->next = nullptr;
            newhead = curr;
            curr = nextnode;
        }
        return newhead;
    }
};