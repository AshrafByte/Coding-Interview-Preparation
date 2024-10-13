//
// Created by Ahmed hesen on 10/13/2024.
//

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
    vector<ListNode *> nodes;
    bool hasCycle(ListNode *head) {
        int num=0;
        ListNode *node = head;
        while(node != NULL){
            num++;
            if(num >= 1e4 + 1) return true;
            node = node->next;
        }
        return false;
    }
};