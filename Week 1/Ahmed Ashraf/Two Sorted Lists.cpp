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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    multiset<int> setu;
    int cnt = 0;
    while (list1 != nullptr)
    {
        setu.insert(list1->val);
        cnt++;
        if (list1->next == nullptr)
            break;
        list1 = list1->next;
    }

    while (list2 != nullptr)
    {
        setu.insert(list2->val);
        cnt++;
        if (list2->next == nullptr)
            break;
        list2 = list2->next;
    }

    if (cnt == 0)
        return nullptr;

    ListNode *list[cnt];
    int i = 0;
    for (auto &e : setu)
        list[i++] = new ListNode(e);

    ListNode *head = list[0];
    for (int i = 0; i < cnt - 1; i++)
    {
        list[i]->next = list[i+1];
    }
    return head;
}
};