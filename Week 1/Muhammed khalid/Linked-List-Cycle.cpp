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
        ListNode* slow = nullptr;
        ListNode* fast = head;
        int pos = -1;
        while(fast!=nullptr){
            if(fast->next == nullptr) return false;
            else if(slow==nullptr && pos==-1){
                slow=head;
                fast = fast->next->next;
                pos++;
            }
            else if(slow!=fast){
                slow = slow->next;
                fast = fast->next->next;
                pos++;
            }
            else if(slow==fast){
                return true;
            }
        }
        return false;
    }
};