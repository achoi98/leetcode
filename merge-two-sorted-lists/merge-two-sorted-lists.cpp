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
        // WLOG, merge l2 into l1
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if (p1->val < p2->val) {
            p1 = l2;
            p2 = l1;
        }
        ListNode* head = p1;
        ListNode* prev = p1;
        
        while (p1 && p2) {
            // val1 > val2 -> merge node2 into list1
            if (p1->val >= p2->val) {
                // p1 is the head of the list, establish prev pointer
                if (p1 == head) {
                    cout << "1\n";
                    ListNode* temp = p2->next;
                    p2->next = p1;
                    prev = p2;
                    head = p2;
                    p2 = temp;
                }
                else {
                    cout << "2\n";
                    ListNode* temp = p2->next;
                    p2->next = p1;
                    prev->next = p2;
                    p2 = temp;
                    prev = prev->next;
                }
            }
            else {
                cout << "3\n";
                p1 = p1->next;
                prev = prev->next;
            }
        }
        
        if (p2) {
            prev->next = p2;
        }
        
        return head;
    }
};