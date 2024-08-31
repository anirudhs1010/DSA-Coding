// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * l, int k) {
    if (l == nullptr)
        return l;
    while (l != nullptr && l->value == k)
        l = l->next;
    ListNode<int> * temp = l;
    ListNode<int> * prev;
    while (temp != nullptr) {
        if (temp->value == k) {
            prev->next = temp->next;
            temp = prev->next;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return l;
}
