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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        int count = 1;
        ListNode* curr = head;
        ListNode* toDelete;
        
        while (count < n + 1 && curr->next != nullptr) {
            curr = curr->next;
            count++;
        }
        toDelete = head;
        while (curr->next != nullptr) {
            curr = curr->next;
            toDelete = toDelete->next;
            count++;
        }
        if (count == n) head = head->next;
        else if (n == 1) toDelete->next = nullptr;
        else toDelete->next = toDelete->next->next;
        return head;
    }
};