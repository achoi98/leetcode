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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* mid = head;
        ListNode* far = head;
        int counter = 1;
        while (far->next != nullptr) {
            far = far->next;
            if (counter == 1) {
                mid = mid->next;
                counter = 0;
            }
            else counter++;
        }
        /*
        while (far != nullptr) {
            far = far->next;
            if (counter == 1) {
                mid = mid->next;
                counter = 0;
            }
            else counter++;
        }
        */
        return mid;
    }
};