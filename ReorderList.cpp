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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        ListNode* prev = NULL;
        slow->next = NULL;
        ListNode* temp = slow;
        while (second != NULL) {
            temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        ListNode* first = head;
        second = prev;
        ListNode* temp2 = NULL;
        while (second != NULL && first != NULL) {
            temp = first->next;
            temp2 = second->next;
            first->next = second;
            second->next = temp;
            first = temp;
            second = temp2;
        }

    }
};
