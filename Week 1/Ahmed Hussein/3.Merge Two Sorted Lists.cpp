//
// Created by Ahmed hesen on 10/7/2024.
//

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        while(list1!=NULL && list2 != NULL){
            ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
            if(list1->val <= list2->val){
                newNode->val = list1->val;
                list1 = list1->next;
            }
            else{
                newNode->val = list2->val;
                list2 = list2->next;
            }
            node->next = newNode;
            node = newNode;
        }
        if(list1 == NULL) node->next = list2;
        else node->next = list1;
        return head->next;
    }
};