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
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* rev = nullptr;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = rev;
            rev = slow;
            slow = temp;
        }
        
        if (fast) slow = slow->next;
        while (slow && rev) {
            if (slow->val != rev->val) return false;
            slow = slow->next;
            rev = rev->next;
        }
        return true;
    }
};