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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* head = new ListNode();
        ListNode* curr;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        if (node1->val >= node2->val) {
            head->val = node2->val;
            node2 = node2->next;
            curr = head;
        }
        else if (node1->val < node2->val) {
            head->val = node1->val;
            node1 = node1->next;
            curr = head;
        }
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val >= node2->val) {
                curr->next = new ListNode(node2->val, nullptr);
                curr = curr->next;
                node2 = node2->next;
            }
            else {
                curr->next = new ListNode(node1->val, nullptr);
                curr = curr->next;
                node1 = node1->next;
            }
        }
        while (node1 != nullptr) {
            curr->next = new ListNode(node1->val, nullptr);
            curr = curr->next;
            node1 = node1->next;
        }
        while (node2 != nullptr) {
            curr->next = new ListNode(node2->val, nullptr);
            curr = curr->next;
            node2 = node2->next;
        }
        return head;
    }
};