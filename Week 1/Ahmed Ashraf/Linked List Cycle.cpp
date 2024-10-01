/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    unordered_map<ListNode*, bool> visited;

public:
    bool hasCycle(ListNode *head)
    {
        while (head != nullptr)
        {
            if (visited[head])
                return true;
            visited[head] = true;
            head = head->next;
        }
        return false;
    }
};