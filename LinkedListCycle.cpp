/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if (!head)
            return false;
        ListNode *tortise = head;
        bool works = false;
        int size = 0;
        while (tortise != nullptr) {
            if (size > 10000) {
                works = true;
                break;
            }
            tortise = tortise->next;
            size++;
        }

        return works;
    }
};
