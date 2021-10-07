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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        if (head == nullptr) return head;
        ListNode* nxt = curr->next;
        while (nxt != nullptr) {
            cout << "curr:" << curr->val << endl;
            cout << "next:" << nxt->val << endl;
            if (curr->val != nxt->val) {
                curr->next = nxt;
                curr = nxt;
            }
            else {
                curr->next = nullptr;
            }
            nxt = nxt->next;
        }
        cout << endl;
        return head;
    }
};