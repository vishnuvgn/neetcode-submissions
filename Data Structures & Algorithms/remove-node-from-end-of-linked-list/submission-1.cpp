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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* leading = head;
        ListNode* trailing = new ListNode(0, head);
        ListNode* dummy = trailing;

        for (int i = 0; i < n; ++i) {
            leading = leading->next;
        }

        while (leading) {
            leading = leading->next;
            trailing = trailing->next;
        }

        trailing->next = trailing->next->next;
        return dummy->next;

    }
};
