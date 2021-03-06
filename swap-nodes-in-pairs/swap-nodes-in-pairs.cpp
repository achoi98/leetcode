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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head -> next == nullptr) return head;
        ListNode* temp = head->next->next;
        if (temp == nullptr) {
            temp = head->next;
            head->next = nullptr;
            temp->next = head;
            return temp;
        }
        ListNode* newhead = head->next;
        head->next->next = head;
        head->next = swapPairs(temp);
        return newhead;
    }
    
};