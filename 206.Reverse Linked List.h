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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        
        ListNode* last = nullptr;
        ListNode* current = head;
        ListNode* next = head->next;
        
        while(current){
            current->next=last;
            
            last=current;
            current=next;
            if(next)
                next=next->next;
        }
        
        return last;
    }
};