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
    ListNode *middleNode(ListNode *head) {
        int cnt = 1;
        ListNode *curr = head;
        while (curr != NULL) {
            curr = curr->next;
            cnt++;
        }

        int x = (cnt) / 2 + 1;
        x = cnt - x;

        while (x--)
            head = head->next;

        return head;

    }
};