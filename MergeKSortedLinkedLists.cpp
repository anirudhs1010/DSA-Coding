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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* a = lists[i];
            while (a != nullptr) {
                v.push_back(a->val);
                a = a->next;
            }
        }
        sort(v.begin(), v.end());
        
         
        ListNode* dummy = new ListNode(0);
        ListNode* n=dummy;
        for (int i = 0; i < v.size(); i++) {
            n->next = new ListNode(v[i]);
            n = n->next;
        }
        return dummy->next;
    }
};
